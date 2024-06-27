/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 01:49:22 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/25 03:16:56 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../../libraries/libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

# define ARG "Invalid number of arguments"
# define CMD "command not found"

typedef struct s_pipex
{
	pid_t	pid;
	int		pipefd[2];
}			t_pipex;

/********************************* PIPEX **************************************/
/********************************* UTILS **************************************/
char	**ft_splitquotes(char *str, int c);
/********************************* UTILS2 *************************************/
char	*ft_path(char **envp);
char	*ft_cmd(char **path, char *str);
/********************************* UTILS3 *************************************/
int		ft_wordsquotes(char *str, int c);
int		ft_len(char *s, char c);
char	*ft_strtrim_quotes(char *s, int start, int len);
/********************************* ERRORS *************************************/
void	ft_commandnotfound(char *error);
void	ft_exit_file_failure(t_pipex *data, int fd, char *argv);
void	ft_exitfailure(char *error);
void	ft_free(void *ptr);
void	ft_freeall(char **ptr);

#endif
