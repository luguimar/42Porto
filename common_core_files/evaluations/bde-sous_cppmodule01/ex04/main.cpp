/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:24:33 by bde-sous          #+#    #+#             */
/*   Updated: 2023/10/31 22:34:49 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string.h>

std::string findReplace(std::string line, std::string find, std::string replace)
{
    int pos;
    
    pos = 0;
    
    if (line.find(find,0) != std::string::npos)
    {
        pos = line.find(find,0);
        line = line.erase(pos,find.length());
        line = line.insert(pos, replace);
        line = line.substr(0, pos + replace.length()) + findReplace(line.substr(pos + replace.length(), std::string::npos), find, replace);
    }
    return(line);
}

int main(int argc, char **argv)
{
    std::ifstream   input;
    std::ofstream   output;
    std::string     str;
    std::string     find;
    std::string     replace;
    std::string     filename;

    if (argc != 4)
    {
        std::cout << "Invalid Number of args" << std::endl;
        return(1);
    }
    else
    {
        if (strlen(argv[2]) == 0)
        {
            std::cout << "Invalid argument" << std::endl;
            return(1);
        }
        filename = argv[1];
        find = argv[2];
        replace = argv[3];
        input.open(filename.c_str(),std::ofstream::in);
        if(!input.is_open())
        {
            std::cout << "failed to open " << argv[1] << std::endl;
            return(1);
        }    
        output.open((filename +".replace").c_str(), std::ofstream::out);
        if(!output.is_open())
        {
            std::cout << "failed to open " << argv[1] << std::endl;
            return(1);
        }
        while (getline(input, str))
        {
            output << findReplace(str, find, replace) << std::endl;
        }
        input.close();
        output.close();
    }
    return(0);
}

