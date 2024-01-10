/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:42:02 by pemiguel          #+#    #+#             */
/*   Updated: 2023/06/14 13:10:54 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <algorithm>

static inline int max(std::vector<int> vec)
{
	return (static_cast<int>(*std::max_element(vec.begin(), vec.end())));
}

static inline int min(std::vector<int> vec)
{
	return (static_cast<int>(*std::min_element(vec.begin(), vec.end())));
}

static inline bool duplicate(std::vector<int> vec, int random_element)
{
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i += 1)
	{
		if (random_element == *i)
			return (true);
	}
	return (false);
}

class Span
{
private:
	std::vector<int> elements;
	unsigned int n;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator = (const Span &other);
	~Span();
	void	addNumber(int new_number);
	int		shortestSpan();
	int		longestSpan();
	void	fillContainer();
	void	printCointaner();
};

#endif
