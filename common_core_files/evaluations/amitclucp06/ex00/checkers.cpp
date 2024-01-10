/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:04:31 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/10 09:46:52 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


bool is_double(const std::string& literal, bool& is_special_literal) {
	char ok = 0;
	size_t i;

	std::string literals[3] = {"-inf", "+inf", "nan"};

	for (i = 0; i < sizeof(literals) / sizeof(literals[0]); ++i) {
		if (literal == literals[i]) {
			is_special_literal = true;
			return true;
		}
	}
	for (i = 0; i < literal.size(); ++i) {
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (literal[i] == '.') {
			++ok;
			continue;
		}
		if (!isdigit(literal[i]))
			return false;
	}
	if (literal[0] == '.' || literal[literal.size() - 1] == '.' || ok != 1)
		return false;

	return true;
}

bool is_float(const std::string& literal, bool& is_special_literal) {
	char ok = 0;
	size_t i;

	std::string literals[3] = {"-inff", "+inff", "nanf"};

	for (i = 0; i < sizeof(literals) / sizeof(literals[0]); ++i) {
		if (literal == literals[i]) {
			is_special_literal = true;
			return true;
		}
	}
	if (literal.size() < 4 || literal[literal.size() - 1] != 'f')
		return false;
	for (i = 0; i < literal.size() - 1; ++i) {
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (literal[i] == '.') {
			++ok;
			continue;
		}
		if (!isdigit(literal[i]))
			return false;
	}
	if (literal[0] == '.' || literal[literal.size() - 2] == '.' || ok != 1)
		return false;

	return true;
}

bool is_int(const std::string& literal) {

	for (size_t i = 0; i < literal.size(); ++i) {
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool is_char(const std::string& literal) {
	if (literal.size() != 1)
		return false;
	return true;
}
