/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 01:52:01 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/26 02:00:17 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_execute(t_pipex *data, char *str, char **envp)
{
	char	*path;
	char	**full_path;
	char	**parse_arg_cmd;
	char	*cmd;

	path = ft_path(envp);
	full_path = ft_split(path, ':');
	parse_arg_cmd = ft_splitquotes(str, ' ');
	cmd = ft_cmd(full_path, parse_arg_cmd[0]);
	if (!cmd)
	{
		ft_freeall(full_path);
		ft_freeall(parse_arg_cmd);
		ft_commandnotfound(CMD);
	}
	if (execve(cmd, parse_arg_cmd, envp) == -1)
	{
		ft_freeall(full_path);
		ft_freeall(parse_arg_cmd);
		ft_free(str);
		ft_free(cmd);
		ft_free(data);
	}
}

static void	ft_parent(t_pipex *data, char *outfile, char *argv, char **envp)
{
	int	fd;

	close(data->pipefd[1]);
	if (access(outfile, F_OK) == 0 && access(outfile, R_OK) != 0)
		ft_exitfailure("");
	if (data -> heredoc)
		fd = open(outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_exit_file_failure(data, fd, argv);
	if (dup2(data->pipefd[0], 0) == -1)
		ft_exitfailure("");
	if (dup2(fd, 1) == -1)
		ft_exitfailure("");
	if (close(fd) == -1)
		ft_exitfailure("");
	if (close(data->pipefd[0]) == -1)
		ft_exitfailure("");
	ft_execute(data, argv, envp);
}

static void	ft_child(t_pipex *data, char *infile, char *argv, char **envp)
{
	int	fd;

	close(data->pipefd[0]);
	if (access(infile, F_OK) != 0 || access(infile, R_OK) != 0)
		ft_exitfailure("");
	fd = open(infile, O_RDONLY, 0644);
	if (fd == -1)
		ft_exit_file_failure(data, fd, argv);
	if (dup2(data->pipefd[1], 1) == -1)
		ft_exitfailure("");
	if (dup2(fd, 0) == -1)
		ft_exitfailure("");
	if (close(fd) == -1)
		ft_exitfailure("");
	if (close(data->pipefd[1]) == -1)
		ft_exitfailure("");
	ft_execute(data, argv, envp);
}

void	here_doc(t_pipex *data, char **argv, char *limiter, int argc)
{
	char	*line;
	int		fd;

	if (argc < 6)
		ft_exitfailure("needed 6 arguments");
	data -> heredoc = 1;
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd == -1)
		ft_exit_file_failure(data, fd, *argv);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (line < 0)
			exit(1);
		if (ft_strncmp(line, limiter, ft_strlen(line)) == '\n')
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_exitfailure("");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	auto int i = 1;
	if (argc >= 5)
	{
		ft_bzero(&data, sizeof(t_pipex));
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 2;
			here_doc(&data, argv, argv[2], argc);
		}
		ft_init(&data);
		if (data.pid == 0)
		{
			while (++i < argc - 2)
				ft_child(&data, argv[1], argv[i], envp);
		}
		ft_parent(&data, argv[argc - 1], argv[argc - 2], envp);
		if (waitpid(data.pid, NULL, 0) == -1)
			perror("waitpid failed");
	}
	else
		return (ft_putendl_fd(ARG, 2), 1);
	return (1);
}
