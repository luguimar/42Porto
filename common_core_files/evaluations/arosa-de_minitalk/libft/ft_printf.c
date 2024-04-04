/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:44:32 by arosa-de          #+#    #+#             */
/*   Updated: 2023/04/15 06:02:20 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIÇÃO: ft_format() verifica cada especificador de formato e chama
	as funções de acordo com os especificadores de formato coletados. 
*/

int	ft_format(va_list args, char specification)
{
	int	x;

	x = 0;
	if (specification == 'i' || specification == 'd')
		x = ft_putnbr(va_arg(args, int), 1);
	else if (specification == 'c')
		x = ft_putchar(va_arg(args, int));
	else if (specification == 's')
		x = ft_putstr(va_arg(args, char *));
	else if (specification == 'u')
		x = ft_print_unsig(va_arg(args, unsigned int), 1);
	else if (specification == 'p')
		x = ft_print_pointer(va_arg(args, unsigned long long));
	else if (specification == 'x')
		x = ft_print_hex(va_arg(args, unsigned int), specification);
	else if (specification == 'X')
		x = ft_print_hex(va_arg(args, unsigned int), specification);
	else if (specification == '%')
		x = ft_putchar('%');
	return (x);
}

/*
	DESCRIÇÃO: ft_printf() função de inicialização: funções de argumentos 
	variáveis ​​de início/fim onde os números de argumentos são indefinidos.
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
