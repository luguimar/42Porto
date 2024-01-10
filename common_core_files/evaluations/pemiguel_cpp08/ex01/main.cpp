/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:43:05 by pemiguel          #+#    #+#             */
/*   Updated: 2023/06/14 13:16:01 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
	try
	{
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
	std::cout << std::endl;
	Span new_sp(10000);
	new_sp.fillContainer();
	new_sp.printCointaner();
	std::cout << std::endl;
	try
	{
		std::cout << "Shortest Span: " << new_sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what();
	}
	try
	{
		std::cout << "Longest Span: " << new_sp.longestSpan() << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what();
	}

	return (0);
}

