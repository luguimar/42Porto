/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:51:16 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 19:28:28 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//Constructors 

Dog::Dog(void) 
{
    this->_sound = "Uof";
    std::cout << "Default constructor called (Dog)" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    this->_sound = "Uof";
    std::cout << this->type << " constructor called (Dog)" << std::endl;
}

Dog::Dog(Dog const & value)
{
    *this = value;
    std::cout << this->type << " copy constructor called (Dog)" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << this->type << " destructor called (Dog)" << std::endl;
}


// OPERATOR 
Dog&  Dog::operator=(Dog const& rhs)
{
    this->type = rhs.getType();
    std::cout << this->type << " operator = overload  called  (Dog)" << std::endl;
    return(*this);
}

void    Dog::makeSound( void ) const
{
    std::cout << this->_sound <<" (Dog)" << std::endl;
}


