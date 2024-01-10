/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:51:12 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 21:15:32 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n,std::string name)
{
    if (n <= 0)
    {
        std::cout << "invalid argument" << std::endl;
        return(0);
    }
    Zombie *z = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        z[i].setName(name);
    }
    return(z);
}