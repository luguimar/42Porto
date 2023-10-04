/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:55:47 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:59 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	inquote(char *s, int index)
{
	int		i;
	char	quote;

	i = -1;
	quote = '\0';
	while (++i <= index)
	{
		if (s[i] == '\0')
			break ;
		if ((s[i - 1] == '\"' || s[i - 1] == '\'') && s[i - 2] != '\\'
			&& quote == '\0')
			quote = s[i];
		else if (s[i] == quote && s[i - 1] != '\\')
			quote = '\0';
	}
	return (quote);
}

char	isquote(char *s, int index)
{
	char	quote;

	quote = '\0';
	if (s[index] == inquote(s, index - 1) && !inquote(s, index))
		quote = inquote(s, index - 1);
	else if (s[index] == inquote(s, index + 1) && !inquote(s, index))
		quote = inquote(s, index - 1);
	return (quote);
}

char	quote(char *s, int index)
{
	if (!inquote(s, index) && !isquote(s, index))
		return ('\0');
	else if (inquote(s, index))
		return (inquote(s, index));
	else
		return (isquote(s, index));
}

int	is_end_quote(char *s, int index)
{
	int	isend;

	isend = 0;
	if (inquote(s, index) && isquote(s, index + 1))
		isend = 1;
	return (isend);
}

int	is_beginning_quote(char *s, int index)
{
	int	isbeginning;

	isbeginning = 0;
	if (inquote(s, index) && isquote(s, index - 1))
		isbeginning = 1;
	return (isbeginning);
}
