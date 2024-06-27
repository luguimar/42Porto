/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 06:54:11 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/25 03:17:45 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void	ft_commandnotfound(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

void	ft_exit_file_failure(t_pipex *data, int fd, char *argv)
{
	if (close(fd) == -1)
		ft_exitfailure("");
	if (close(data->pipefd[0]) == -1)
		ft_exitfailure("");
	if (close(data->pipefd[1]) == -1)
		ft_exitfailure("");
	perror(argv);
	exit(1);
}

void	ft_exitfailure(char *error)
{
	perror(error);
	exit(1);
}

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

void	ft_freeall(char **ptr)
{
	int	i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
		ft_free(ptr[i]);
	free(ptr);
	ptr = NULL;
}
