/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:11:30 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/31 18:56:21 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::~Weapon(void)
{
    
}

Weapon::Weapon(std::string name) : _type(name)
{

}

std::string const& Weapon::getType(void) const
{
    return(this->_type);
}

void Weapon::setType(std::string value)
{
    this->_type = value;
}