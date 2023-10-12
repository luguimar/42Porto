/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:18:14 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/12 21:38:05 by luguimar         ###   ########.fr       */
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
