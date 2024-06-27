/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 01:47:46 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/26 22:45:27 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

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

static void	ft_parent(t_pipex *data, int argc, char **argv, char **envp)
{
	int	fd;

	close(data->pipefd[1]);
	if (access(argv[argc - 1], F_OK) == 0 && access(argv[argc - 1], R_OK) != 0)
		ft_exitfailure("");
	fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_exit_file_failure(data, fd, argv[argc - 1]);
	if (dup2(data->pipefd[0], 0) == -1)
		ft_exitfailure("");
	if (dup2(fd, 1) == -1)
		ft_exitfailure("");
	if (close(fd) == -1)
		ft_exitfailure("");
	if (close(data->pipefd[0]) == -1)
		ft_exitfailure("");
	ft_execute(data, argv[3], envp);
}

static void	ft_child(t_pipex *data, char **argv, char **envp)
{
	int	fd;

	close(data->pipefd[0]);
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
		ft_exitfailure("");
	fd = open(argv[1], O_RDONLY, 0644);
	if (fd == -1)
		ft_exit_file_failure(data, fd, argv[1]);
	if (dup2(data->pipefd[1], 1) == -1)
		ft_exitfailure("");
	if (dup2(fd, 0) == -1)
		ft_exitfailure("");
	if (close(fd) == -1)
		ft_exitfailure("");
	if (close(data->pipefd[1]) == -1)
		ft_exitfailure("");
	ft_execute(data, argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc == 5)
	{
		ft_bzero(&data, sizeof(t_pipex));
		if (pipe(data.pipefd) == -1)
			ft_exitfailure("");
		data.pid = fork();
		if (data.pid == -1)
			ft_exitfailure("");
		if (data.pid == 0)
			ft_child(&data, argv, envp);
		ft_parent(&data, argc, argv, envp);
		if (waitpid(data.pid, NULL, 0) == -1)
			perror("waitpid failed");
	}
	else
		return (ft_putendl_fd(ARG, 2), 1);
	return (1);
}
