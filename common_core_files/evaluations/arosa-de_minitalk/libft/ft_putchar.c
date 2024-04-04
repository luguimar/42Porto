/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:48:45 by arosa-de          #+#    #+#             */
/*   Updated: 2024/01/16 01:07:40 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIÇÃO: putchar() grava um caractere especificado na unidade de saída
	fornecida.
*/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
