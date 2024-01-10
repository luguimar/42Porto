/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:51:16 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 19:28:28 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Constructors 

Animal::Animal(void) 
{
    std::cout << "Default constructor called (Animal)" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << this->type << " constructor called (Animal)" << std::endl;
}

Animal::Animal(Animal const & value)
{
    *this = value;
    std::cout << this->type << " copy constructor called (Animal)" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << this->type << " destructor called (Animal)" << std::endl;
}


// OPERATOR 
Animal&  Animal::operator=(Animal const& rhs)
{
    this->type = rhs.getType();
    std::cout << this->type << " operator = overload  called  (Animal)" << std::endl;
    return(*this);
}

std::string     Animal::getType( void ) const
{
    return(this->type);
}

void    Animal::makeSound( void ) const
{
    std::cout << "Make Sound  (Animal)" << std::endl;
}

