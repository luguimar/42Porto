/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:07:51 by luguimar          #+#    #+#             */
/*   Updated: 2023/09/27 21:24:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>

static void	exec_command(char **path, char ***envp, char ***args)
{
	if (!(*path) || !(*envp))
	{
		if (*args[0])
		{
			dup2(STDERR_FILENO, STDOUT_FILENO);
			ft_printf("pipex: %s: command not found\n", *args[0]);
			if (*path)
				free(*path);
			free_array_of_strings(*args);
			exit(127);
		}
		if (*path)
			free(*path);
		exit(1);
	}
	execve(*path, *args, *envp);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("pipex: %s: command not found\n", *args[0]);
	free(*path);
	free_array_of_strings(*args);
	exit(127);
}

static void	check_error(int status, char *message, char ***args, char **path)
{
	if (status == -1)
	{
		if (*args)
			free_array_of_strings(*args);
		if (*path)
			free(*path);
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
	path = ft_split(envp[i] + 5, ':');
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
	free_array_of_strings(path);
	return (NULL);
}

static void	redirect_files(char *in_file, char *cmd, char **envp)
{
	int		cid;
	int		pipefd[2];
	char	*path;
	char	**args;

	check_error(pipe(pipefd), "pipe", NULL, NULL);
	cid = fork();
	if (cid == 0)
	{
		args = ft_split(cmd, ' ');
		path = get_right_path(args[0], envp);
		check_error(access(in_file, R_OK), in_file, &args, &path);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_command(&path, &envp, &args);
	}
	else if (cid == -1)
		check_error(-1, "child process", NULL, NULL);
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		wait(&cid);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**args;

	if (argc == 5)
	{
		path = NULL;
		args = NULL;
		fd_in = open(argv[1], O_RDONLY);
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		check_error(access(argv[argc - 1], W_OK), argv[argc - 1], &args, &path);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		redirect_files(argv[1], argv[2], envp);
		args = ft_split(argv[3], ' ');
		path = get_right_path(args[0], envp);
		exec_command(&path, &envp, &args);
	}
	else
		ft_printf("Wrong number of arguments!\n");
	return (1);
}
