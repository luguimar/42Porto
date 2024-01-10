/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:07:09 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/29 19:10:37 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    Zombie *z = zombieHorde(10, "tete");
    for (int i = 0; i < 10 ; i++)
    {
        z[i].announce();
    }
    delete [] z;
    return (0);
}