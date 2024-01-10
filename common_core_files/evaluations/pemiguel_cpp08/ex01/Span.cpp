/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:42:10 by pemiguel          #+#    #+#             */
/*   Updated: 2023/06/14 13:13:25 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n) : n(n)
{
}

Span::Span(const Span &other) : elements(other.elements), n(other.n)
{
}

Span &Span::operator = (const Span &other)
{
	this->elements = other.elements;
	this->n = other.n;

	return (*this);
}

Span::~Span()
{
}

void    Span::addNumber(int new_number)
{
	try
	{
		if (this->elements.size() == this->n)
			throw std::exception();
		this->elements.push_back(new_number);
	}
	catch(const std::exception &error)
	{
		std::cerr << "Span class is already filled!" << std::endl;
	}
}

int Span::longestSpan()
{
	if (elements.size() <= 1)
		throw std::runtime_error("No span can be found!");
	return (max(this->elements) - min(this->elements));
}

int Span::shortestSpan()
{
	if (elements.size() <= 1)
		throw std::runtime_error("No span can be found!");
	int shortestSpan = std::abs(elements.at(0) - elements.at(1));
	for (std::vector<int>::iterator i = this->elements.begin(); i != this->elements.end(); i += 1)
	{
		for (std::vector<int>::iterator j = i + 1; j != this->elements.end(); j += 1)
		{
			if (std::abs(*i - *j) < shortestSpan)
				shortestSpan = std::abs(*i - *j);
		}
	}
	return (shortestSpan);
}

void	Span::fillContainer()
{
	int	random_element;
	srand(time(NULL));
	for (unsigned int j = 0; j != this->n; j += 1)
	{
		while (true)
		{
			random_element = rand() % 100;// 1- 100
			if (this->elements.size() == 0 || !duplicate(this->elements, random_element))
				break ;
		}
		this->elements.push_back(random_element);
	}
}

void	Span::printCointaner()
{
	std::cout << "Container" << std::endl;
	for (std::vector<int>::iterator i = this->elements.begin(); i < this->elements.end(); i += 1)
		std::cout << *i << std::endl;
}
