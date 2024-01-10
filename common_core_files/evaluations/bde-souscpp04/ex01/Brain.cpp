/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:14:53 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/20 22:56:32 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//Constructors 

Brain::Brain(void) 
{
    std::cout << "Default constructor called (Brain)" << std::endl;
}

// Brain::Brain(std::string type) : 
// {
//     std::cout << " constructor called (Brain)" << std::endl;
// }

Brain::Brain(Brain const & value)
{
    *this = value;
    std::cout << "Default copy constructor called (Brain)" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Default destructor called (Brain)" << std::endl;
}


// OPERATOR 
Brain&  Brain::operator=(Brain const& rhs)
{
    //this->ideas = rhs.ideas;
    (void)rhs;
    std::cout << " operator = overload  called  (Brain)" << std::endl;
    return(*this);
}
