/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:51:16 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 21:37:30 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//Constructors 

WrongCat::WrongCat(void) 
{
    this->_sound = "Miau";
    std::cout << "Default constructor called (WrongCat)" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    this->_sound = "Miau";
    std::cout << this->type << " constructor called (WrongCat)" << std::endl;
}

WrongCat::WrongCat(WrongCat const & value)
{
    *this = value;
    std::cout << this->type << " copy constructor called (WrongCat)" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->type << " destructor called (WrongCat)" << std::endl;
}


// OPERATOR 
WrongCat&  WrongCat::operator=(WrongCat const& rhs)
{
    this->type = rhs.getType();
    std::cout << this->type << " operator = overload  called  (WrongCat)" << std::endl;
    return(*this);
}

void    WrongCat::makeSound( void ) const
{
    std::cout << this->_sound <<" (WrongCat)" << std::endl;
}



