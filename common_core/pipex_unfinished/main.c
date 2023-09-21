/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:07:51 by luguimar          #+#    #+#             */
/*   Updated: 2023/09/21 20:43:55 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_right_path(char *cmd, char **envp)
{
	int	i;
	char	**path;
	char	*right_path;

	i = 0
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i], ':');
	while ()
}

static void	redirect_files(char *in_file, cahr *cmd, char ** envp)
{
	int	cid;
	int	pipefd[2];
	char	*path;

	path = get_right_path(cmd, envp);
	check_error(pipe(pipefd), "pipe");
	cih = fork();
	if (cid == 0)
	{
		check_error(access(in_file, R_OK), in_file);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execve()
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
	int	fd_in;
	int	fd_out;

	if (argc == 5)
	{
		fd_in = open(argv[1], 0_RDONLY);
		fd_out = open(argv[argc - 1], 0_WRONLY | 0_CREAT | 0_TRUNC, 0777);
		check_file(access(argv[argc - 1], W_ok), argv[argc - 1]);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		redirect_files(argv[1], argv[2], envp);
	}
	else
	{
		ft_printf("Wrong number of arguments!!!\n");
		ft_printf("The correct usage is:\n");
		ft_printf("   ./pipex infile cmd1 cmd2 outfile");
	}
}
