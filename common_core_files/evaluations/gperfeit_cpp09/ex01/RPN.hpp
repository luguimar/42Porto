/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:37:23 by gperfeit          #+#    #+#             */
/*   Updated: 2024/05/22 00:37:24 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <stack>

class Rpn {
	private:
		std::stack<double> nbrs;

	public:
		Rpn();
		~Rpn();
		Rpn(Rpn const &src);
		Rpn &operator=(Rpn const &rhs);
		int ft_isdigit(char nbr);
		void parsing(char **av);
		double calculation(char **av);
		void calc_sign(char sign);

};

#endif
