/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:28:03 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/31 20:07:05 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon& type) : _weapon(&type)
{

}

HumanA::~HumanA(void)
{
    
}

HumanA::HumanA(std::string name, Weapon& type ) : _name(name), _weapon(&type)
{

}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}