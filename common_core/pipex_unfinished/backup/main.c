/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:07:51 by luguimar          #+#    #+#             */
/*   Updated: 2023/09/22 19:57:40 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>

void	check_error(int status, char *message)
{
	if (status == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(message);
		exit(1);
	}
	return ;
}

static char	*get_right_path(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*right_path;
	char	*add_slash;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i], ':');
	i = 0;
	while (path[i])
	{
		add_slash = ft_strjoin(path[i], "/");
		right_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(right_path, F_OK) == 0)
		{
			free_array_of_strings(path);
			return (right_path);
		}
		free(right_path);
		i++;
	}
	return (NULL);
}

static void	redirect_files(char *in_file, char *cmd, char **envp)
{
	int		cid;
	int		pipefd[2];
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	path = get_right_path(args[0], envp);
	check_error(pipe(pipefd), "pipe");
	cid = fork();
	if (cid == 0)
	{
		check_error(access(in_file, R_OK), in_file);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execve(path, args, envp);
		exit(127);
	}
	else if (cid == -1)
		check_error(-1, "child process");
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	char	*path_cmd2;
	char	**args_cmd2;

	args_cmd2 = ft_split(argv[3], ' ');
	path_cmd2 = get_right_path(args_cmd2[0], envp);
	if (argc == 5)
	{
		fd_in = open(argv[1], O_RDONLY);
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		check_error(access(argv[argc - 1], W_OK), argv[argc - 1]);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		redirect_files(argv[1], argv[2], envp);
		execve(path_cmd2, args_cmd2, envp);
		exit(127);
	}
	else
	{
		ft_printf("Wrong number of arguments!!!\n");
		ft_printf("The correct usage is:\n");
		ft_printf("   ./pipex infile cmd1 cmd2 outfile");
	}
}
