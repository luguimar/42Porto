/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:37:09 by gperfeit          #+#    #+#             */
/*   Updated: 2024/05/22 00:37:10 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: " << av[0] << " \" 1 1 + \"" << std::endl;
		return (1);
	}
	Rpn calc_it;
	calc_it.parsing(av);	
	std::cout << calc_it.calculation(av) << std::endl;
	return (0);
}
