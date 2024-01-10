/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:16:50 by fernacar          #+#    #+#             */
/*   Updated: 2023/12/18 22:48:16 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << ">> Create ClapTrap" << std::endl;
	ClapTrap ct("Ze");

	std::cout << std::endl;

	std::cout << ">> show basic actions" << std::endl;
	ct.attack("Esteves");
	ct.beRepaired(5);
	ct.takeDamage(8);
	ct.beRepaired(6);
	ct.beRepaired(4);
	
	std::cout << std::endl;

	std::cout << ">> spend all energy points" << std::endl;
	ct.attack("Esteves");
	ct.attack("Esteves");
	ct.attack("Esteves");
	ct.attack("Esteves");
	ct.attack("Esteves");
	ct.attack("Esteves");
	ct.attack("Esteves");

	std::cout << std::endl;
	
	std::cout << ">> no energy left to do actions" << std::endl;
	ct.attack("Esteves");
	ct.beRepaired(10);

	std::cout << std::endl;

	std::cout << ">> kill it" << std::endl;
	ct.takeDamage(9999);

	std::cout << std::endl;

	std::cout << ">> no hit points left to do actions" << std::endl;
	ct.attack("Esteves");
	ct.beRepaired(10);
	ct.takeDamage(5);

	std::cout << std::endl;

	return 0;
}