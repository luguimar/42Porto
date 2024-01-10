/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:51:16 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 19:28:28 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//Constructors 

WrongAnimal::WrongAnimal(void) 
{
    std::cout << "Default constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << this->type << " constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & value)
{
    *this = value;
    std::cout << this->type << " copy constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << this->type << " destructor called (WrongAnimal)" << std::endl;
}


// OPERATOR 
WrongAnimal&  WrongAnimal::operator=(WrongAnimal const& rhs)
{
    this->type = rhs.getType();
    std::cout << this->type << " operator = overload  called  (WrongAnimal)" << std::endl;
    return(*this);
}

std::string     WrongAnimal::getType( void ) const
{
    return(this->type);
}

void    WrongAnimal::makeSound( void ) const
{
    std::cout << "Make Sound  (WrongAnimal)" << std::endl;
}

