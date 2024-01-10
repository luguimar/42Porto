/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:51:16 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 19:28:28 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//Constructors 

Cat::Cat(void) 
{
    this->_sound = "Miau";
    std::cout << "Default constructor called (Cat)" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(std::string type) : A_Animal(type)
{
    this->_sound = "Miau";
    std::cout << this->type << " constructor called (Cat)" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(Cat const & value)
{
    *this = value;
    std::cout << this->type << " copy constructor called (Cat)" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << this->type << " destructor called (Cat)" << std::endl;
    delete(this->_brain);
}


// OPERATOR 
Cat&  Cat::operator=(Cat const& rhs)
{
    this->type = rhs.getType();
    std::cout << this->type << " operator = overload  called  (Cat)" << std::endl;
    return(*this);
}

void    Cat::makeSound( void ) const
{
    std::cout << this->_sound <<" (Cat)" << std::endl;
}



