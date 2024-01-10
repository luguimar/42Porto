/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:33:52 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/01 18:07:10 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
    _levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";
    _ptr[0] = &Harl::debug;
    _ptr[1] = &Harl::info;
    _ptr[2] = &Harl::warning;
    _ptr[3] = &Harl::error;
}



Harl::~Harl( void )
{

}

void    Harl::debug(void)
{
    std::cout << "Debug Level" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "Info Level" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "Warning Level" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "Error Level" << std::endl;
}

void    Harl::complain( std::string level )
{
    for (int i = 0; i < 4; i++)
        if (_levels[i] == level) {(this->*_ptr[i])();}
}