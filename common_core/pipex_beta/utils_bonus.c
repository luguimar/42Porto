/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:18:14 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/13 01:54:27 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup2stdout(int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
}

void	dup2stdin(int *pipefd)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
}

void	dup2redirect(int *fd, char **argv, char **envp)
{
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[ft_matrixlen((void **)argv) - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0664);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	redirect_files(2, argv, envp);
}
