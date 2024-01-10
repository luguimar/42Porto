/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:04:34 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/10 09:46:27 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define MAX_TO_PRECISION 1000000

bool fit_in(e_types type, long double value) {
	if (type == CHAR) {
		if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())
			return false;
		return true;
	} else if (type == INT) {
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
			return false;
		return true;
	} else if (type == FLOAT) {
		if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
			return false;
		return true;
	} else if (type == DOUBLE) {
		if (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min())
			return false;
		return true;
	}convert
	return false;
}

void print_char(long double x, bool is_special_literal) {
	char c = static_cast<char>(x);
	
	std::cout << "char: ";
	if (c < 0 || c > 127 || fit_in(CHAR, x) == false || is_special_literal) {
		std::cout << "impossible";
	} else if (c <= 31 || c == 127) {
		std::cout << "invisible";
	} else {
		std::cout << c;
	}

	std::cout << std::endl;
}

void print_int(long double x, bool is_special_literal) {
	print_char(x, is_special_literal);
	int li = static_cast<int>(x);

	std::cout << "int: ";
	if (fit_in(INT, x) == false || is_special_literal) {
		std::cout << "impossible";
	} else {
		std::cout << static_cast<int>(li);
	}
	std::cout << std::endl;
}

void print_float(long double x, bool is_special_literal) {
	print_int(x, is_special_literal);

	float value = static_cast<float>(x);
	std::cout << "float: ";
	if (fit_in(FLOAT, value) == false) {
		std::cout << "impossible";
	} else {
		std::cout << value;
		float fraction = std::fabs(x - std::floor(x));
		if (fraction == 0.0f && value < MAX_TO_PRECISION)
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;
}

void print_double(const std::string& literal, bool is_special_literal) {
	long double value;
	if (literal.size() == 1 && (literal[0] < '0' || literal[0] > '9'))
		value = static_cast<long double>(literal[0]);
	else
		value = strtold(literal.c_str(), NULL);
	print_float(value, is_special_literal);

	std::cout << "double: ";
	if (fit_in(DOUBLE, value) == false) {
		std::cout << "impossible";
	} else {
		double d = static_cast<double>(value);
		std::cout << d;
		float fraction = std::fabs(d - std::floor(d));
		if (fraction == 0.0f && d < MAX_TO_PRECISION)
			std::cout << ".0";
	}
	std::cout << std::endl;
}
