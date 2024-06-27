/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 00:58:25 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/25 03:17:45 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

char	*ft_path(char **envp)
{
	if (!envp)
		return ((void *)0);
	while (ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	return (*envp + 5);
}

char	*ft_cmd(char **path, char *str)
{
	char	*cmd;
	char	*tmp;

	while (*path)
	{
		if (!str)
			return (NULL);
		tmp = ft_strjoin(*path, "/");
		if (!tmp)
			return (NULL);
		cmd = ft_strjoin(tmp, str);
		if (!cmd)
			return (NULL);
		ft_free(tmp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		ft_free(cmd);
		path++;
	}
	return (NULL);
}
