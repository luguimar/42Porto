/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:15:14 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/02 17:50:33 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>

#include <algorithm>
#include <cctype>

#include <fstream>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> prices;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		void readBitcoinPrices(const std::string& filename);
		void calculateValues(const std::string& inputFilename);
		int parseDate(const std::string& date);
		std::string spaces_trim(std::string s);
		std::string spacestrim(std::string s);
};

#endif
