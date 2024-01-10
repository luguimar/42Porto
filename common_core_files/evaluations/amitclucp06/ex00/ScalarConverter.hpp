/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:08:01 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/10 09:46:43 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>

#include <cmath>
#include <cstdlib>
#include <cctype>

enum e_types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

/* checkers */
bool is_double(const std::string& literal, bool& is_special_literal);
bool is_float(const std::string& literal, bool& is_special_literal);
bool is_int(const std::string& literal);
bool is_char(const std::string& literal);

/* printers */
void print_double(const std::string& literal, bool is_special_lit);


class ScalarConverter {
 private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& sc);
	ScalarConverter& operator=(const ScalarConverter& sc);

 public:
	~ScalarConverter();
	static void convert(const std::string& liral);
};

#endif // SCALAR_CONVERTER_HPP
