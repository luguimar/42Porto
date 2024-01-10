/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:51:21 by pemontei          #+#    #+#             */
/*   Updated: 2023/04/17 21:59:07 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*memloc;

	memloc = malloc(nitems * size);
	if (!(memloc))
	{
		return (0);
	}
	ft_bzero(memloc, nitems * size);
	return (memloc);
}

/*int main(void)
{
    int *arr;
    size_t n = 5;
    size_t s = sizeof(int);

    arr = (int *)ft_calloc(n, s);
    if (arr == NULL) {
        printf("Error: memory allocation failed\n");
        return 1;
    }
	
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (size_t i = 0; i < n; i++) {
        if (arr[i] != 0) {
            printf("\nError: memory not set to 0\n");
            return 1;
        }
    }
    free(arr);
    return 0;
}*/
