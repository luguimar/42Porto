/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:39:59 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/29 19:27:32 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN -250
#define MAX 250
#define QTDE 100 //needs to be smaller than MAX

void shuffle(int *array) {
   for (int i = MAX - MIN - 1; i > 0; i--) {
       int j = rand() % (i + 1);
       int tmp = array[j];
       array[j] = array[i];
       array[i] = tmp;
   }
}

int main(void) {
   srand(time(NULL));
   int * numeros = malloc((MAX - MIN) * sizeof(int));
   if (!numeros) exit(EXIT_FAILURE);
   for (int i = 0; i < MAX - MIN; i++) {
       numeros[i] = i + MIN;
   }
   shuffle(numeros);
   for (int i = 0; i < QTDE; i++) {
       printf("%d ", numeros[i]);
   }
   return 0;
}
