/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:51:16 by bde-sous          #+#    #+#             */
/*   Updated: 2023/12/08 21:36:26 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

//Constructors 

A_Animal::A_Animal(void) 
{
    std::cout << "Default constructor called (A_Animal)" << std::endl;
}

A_Animal::A_Animal(std::string type) : type(type)
{
    std::cout << this->type << " constructor called (A_Animal)" << std::endl;
}

A_Animal::A_Animal(A_Animal const & value)
{
    *this = value;
    std::cout << this->type << " copy constructor called (A_Animal)" << std::endl;
}

A_Animal::~A_Animal(void)
{
    std::cout << this->type << " destructor called (A_Animal)" << std::endl;
}


// OPERATOR 
A_Animal&  A_Animal::operator=(A_Animal const& rhs)
{
    this->type = rhs.getType();
    std::cout << this->type << " operator = overload  called  (A_Animal)" << std::endl;
    return(*this);
}

std::string     A_Animal::getType( void ) const
{
    return(this->type);
}

void    A_Animal::makeSound( void ) const
{
    std::cout << "Make Sound  (A_Animal)" << std::endl;
}

