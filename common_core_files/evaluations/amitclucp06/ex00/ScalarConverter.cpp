/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:07:49 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/10 09:46:29 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string& literal) {
	bool is_special_literal = false;
	if (is_double(literal, is_special_literal) || is_float(literal, is_special_literal) || is_int(literal) || is_char(literal)) {
		print_double(literal, is_special_literal);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
