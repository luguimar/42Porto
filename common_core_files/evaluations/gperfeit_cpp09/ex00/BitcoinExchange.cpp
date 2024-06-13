/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:15:08 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/09 16:38:27 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	this->prices = src.prices;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->prices = rhs.prices;
	}
	return *this;
}

void BitcoinExchange::readBitcoinPrices(std::string const &filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double price;
        std::getline(iss, date, ',');
        iss >> price;
        this->prices[date] = price;

    }
}

int BitcoinExchange::parseDate(std::string const &date) {
    if (date.size() != 10)
        return 0;
    if (date[4] != '-' || date[7] != '-')
        return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return 0;
    }
    return 1;
}

std::string BitcoinExchange::spaces_trim(std::string s) {
    std::string::size_type end = s.find_last_not_of(" \n\r\t");
    if(end != std::string::npos)
        s.erase(end + 1);
    else
        s.clear();
    return s;
}

std::string BitcoinExchange::spacestrim(std::string s) {
    for (std::string::iterator i = s.begin(); i != s.end(); )
    {
        if (*i == ' ' || *i == ' ')
            s.erase(i);
        else
            i++;
    }
    return s;
}

void BitcoinExchange::calculateValues(std::string const &inputFilename) {
    std::ifstream file(inputFilename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error opening file " << inputFilename << "\n";
        return;
    }
    
    std::string header;
    std::getline(file, header);
    header = spacestrim(header);
    //std::cout << header << std::endl;
    if (header != "date|value") {
        std::cerr << "Error: Invalid header: " << header << "\n";
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double amount;
        std::getline(iss, date, '|');
        date = spaces_trim(date);
        if (!(iss >> amount))
            std::cerr << "Error: bad input => " << line << "\n";
        else if (!this->parseDate(date))
            std::cerr << "Error: bad input => " << date << "\n";
        else if (date.size() != 10)
            std::cerr << "Error: bad input => " << date << "\n";
        else if (amount <= 0)
            std::cerr << "Error: not a positive number." << "\n";
        else if (amount > 1000)
            std::cerr << "Error: too large a number." << "\n";
        else {
            std::map<std::string, double>::iterator it = this->prices.upper_bound(date);
            if (it != this->prices.begin()) {
                --it;  
                double value = amount * it->second;
                if (value >= 2147483647)
                    std::cerr << "Error: too large a number." << "\n";
                else
                    std::cout << date << " => " << value << "\n";
            } else {
                std::cerr << "Error: No date found in prices map that is less than or equal to: " << date << "\n";
            }
        }
    }
}
