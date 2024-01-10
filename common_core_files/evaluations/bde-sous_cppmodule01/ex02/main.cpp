/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:24:33 by bde-sous          #+#    #+#             */
/*   Updated: 2023/11/29 19:15:17 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "str Value: " << str << " Add: " << &str << std::endl;
    std::cout << "ptr Value: " << stringPTR << " Add: " << &stringPTR << std::endl;
    std::cout << "ref Value: " << stringREF << " Add: " << &stringREF << std::endl;

    std::cout << "Add str: " << &str << " value: " << str << std::endl;
    std::cout << "Add stringPTR: " << &stringPTR << " value: " << stringPTR << std::endl;
    std::cout << "Add stringREF: " << &stringREF << " value: " << stringREF << std::endl;

    str = "Batatinhas";

    std::cout << "Add str: " << &str << " value: " << str << std::endl;
    std::cout << "Add stringPTR: " << &stringPTR << " value: " << stringPTR << std::endl;
    std::cout << "Add stringREF: " << &stringREF << " value: " << stringREF << std::endl;
}

