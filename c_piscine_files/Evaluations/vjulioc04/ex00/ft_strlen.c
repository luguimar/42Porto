/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjulio-d <vjulio-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:56 by vjulio-d          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:20 by vjulio-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* int main(void)
{
    char    str[] = "Teste de função";
    char    resp[] = {ft_strlen(str)};
    printf("%i", ft_strlen());
} */
