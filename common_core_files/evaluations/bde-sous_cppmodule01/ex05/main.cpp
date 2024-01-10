/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:24:33 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/02 18:24:14 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"



int main(int argc, char **argv)
{
    Harl    teste;

    if (argc != 2)
    {
        std::cout << "Invalid Number of args" << std::endl;
        return(1);
    }
    teste.complain(argv[1]);
    return(0);
}

