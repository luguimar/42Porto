/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:07:09 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 21:25:23 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    randomChump("batatinhas");

    Zombie *z = newZombie("yoyo");
    z->announce();
    delete z;
    return (0);
}