/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:22:52 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/13 01:17:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

void	dup2stdout(int *pipefd);
void	dup2stdin(int *pipefd);
void	dup2redirect(int *fd, char **argv, char **envp);
void	redirect_files(int i, char *argv[], char **envp);

#endif
