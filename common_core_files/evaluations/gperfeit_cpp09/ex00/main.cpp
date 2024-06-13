/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:55 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/02 17:36:48 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Usage: " << argv[0] << " <input file>\n";
        return 1;
    }
    
    if (!std::ifstream("data.csv")) {
        std::cerr << "Error: Database file data.csv does not exist\n";
        return 1;
    }
    BitcoinExchange obj;
    obj.readBitcoinPrices("data.csv");

    std::string inputFilename = argv[1];
    if (!std::ifstream(argv[1])) {
        std::cerr << "Error: Input file " << inputFilename << " does not exist\n";
        return 1;
    }    
    obj.calculateValues(inputFilename);

    return 0;
}
