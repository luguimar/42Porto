/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:37:17 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/02 21:15:12 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn() {}

Rpn::~Rpn() {}

Rpn::Rpn(Rpn const &that) {
	*this = that;
}

Rpn &Rpn::operator=(Rpn const &rhs) {
	if (this != &rhs)
		this->nbrs = rhs.nbrs;
	return (*this);
}

int Rpn::ft_isdigit(char nbr) {
	if (nbr <= '9' && nbr >= '0')
		return 0;
	return 1;
}

void Rpn::parsing(char **av) {
	int i = 0;
	int i_last_sign = 0;
	int i_last_digit = 0;

	while (ft_isdigit(av[1][i])) {
		if (av[1][i] == ' ') {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
	i = 0;
	while (av[1][i])
		i++;
	i--;
	while (ft_isdigit(av[1][i]) && av[1][i] != '/' && av[1][i] != '*' && av[1][i] != '+' && av[1][i] != '-' ) {
		if (av[1][i] == ' ') {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i--;
	}
	i = 0;
	while (av[1][i]) {
		if (av[1][i] == ' ')
			;
		else if (ft_isdigit(av[1][i]) && (av[1][i] != '/' && av[1][i] != '*' && av[1][i] != '+' && av[1][i] != '-')) {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		else if ((!ft_isdigit(av[1][i]) || av[1][i] == '/' || av[1][i] == '*' || av[1][i] == '+' || av[1][i] == '-' ) && ((av[1][i-1] != ' ' && i != 0) || (av[1][i+1] != ' ' && av[1][i+1] != '\0'))) {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		else if (!ft_isdigit(av[1][i])) {
			i_last_digit++;
		}
		else if (av[1][i] == '/' || av[1][i] == '*' || av[1][i] == '+' || av[1][i] == '-') {
			i_last_sign++;
		}
		if (i_last_sign > 0 && i_last_digit < 2) {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		if (av[1][i] == ' ' && av[1][i - 1] == ' ') {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
	if (i_last_digit - i_last_sign != 1) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
}

void Rpn::calc_sign(char sign) {
	double tmp = 0;
	if (sign == '*')
	{
		tmp = this->nbrs.top();
		this->nbrs.pop();
		tmp = this->nbrs.top() * tmp;
		this->nbrs.pop();
		this->nbrs.push(tmp);
	}
	else if (sign == '/')
	{
		tmp = this->nbrs.top();
		this->nbrs.pop();
		tmp = this->nbrs.top() / tmp;
		this->nbrs.pop();
		this->nbrs.push(tmp);
	}
	else if (sign == '+')
	{
		tmp = this->nbrs.top();
		this->nbrs.pop();
		tmp = this->nbrs.top() + tmp;
		this->nbrs.pop();
		this->nbrs.push(tmp);
	}
	else if (sign == '-')
	{
		tmp = this->nbrs.top();
		this->nbrs.pop();
		tmp = this->nbrs.top() - tmp;
		this->nbrs.pop();
		this->nbrs.push(tmp);
	}
}

double Rpn::calculation(char **av) {
	size_t i = 0;

	while (av[1][i] != '\0') {
		if (!ft_isdigit(av[1][i]))
			this->nbrs.push(av[1][i] - '0');
		else if (av[1][i] == '/' || av[1][i] == '*' || av[1][i] == '+' || av[1][i] == '-')
			calc_sign(av[1][i]);
		i++;
	}
	return this->nbrs.top();
}
