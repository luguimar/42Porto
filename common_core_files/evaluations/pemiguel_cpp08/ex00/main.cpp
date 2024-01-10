/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:10:34 by pemiguel          #+#    #+#             */
/*   Updated: 2023/06/14 12:59:13 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

/*
Associative containers are a category of containers in C++ that store elements in a sorted and efficient manner based on a key.

Examples:
std::set: It stores a collection of unique keys in a sorted order. It does not allow duplicate elements.

std::multiset: Similar to std::set, it stores a collection of keys in a sorted order, but allows duplicate elements.

std::map: It stores a collection of key-value pairs in a sorted order based on the keys. Each key is unique, and associated with a value.

std::multimap: Similar to std::map, it stores key-value pairs in a sorted order based on the keys, but allows duplicate keys and associated values.
*/

int main()
{
	/*vectors*/
	std::vector<int> container;
	for (int i = 1; i <= 128; i *= 2)
		container.push_back(i);
	easyfind(container, 7);

	/*lists*/
	std::list<int> intList;
	for (int i = 1; i <= 300; i *= 3)
		intList.push_back(i);
	easyfind(intList, 7);

	return (0);
}
