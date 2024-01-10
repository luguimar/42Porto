/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:11:02 by pemiguel          #+#    #+#             */
/*   Updated: 2023/05/28 21:05:12 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>

/*Iterators are used to point at the memory addresses of STL containers.

Operations of iterators:
begin(): Returns the BEGINNING position of the container.
end(): Returns the AFTER END position of the container.
*/

/*We need to especify that T::iterator is a type, therefore we use 'typename'
Also we need to tell the compiler that iterator belongs to container type 'T', in this case vector<int>::iterator*/

/*Since iterators do not have the operator overload '<<' we use the function std::distance()
that returns the distance between two input iterators (first parameter being the first, and second parameter the last)*/
void	easyfind(T &container, int toFind)
{
	try
	{
		typename T::iterator it = std::find(container.begin(), container.end(), toFind);
		if (it == container.end())
			throw std::exception();
		std::cout << "Found " << toFind << " at index: " << std::distance(container.begin(), it) << std::endl;
	}
	catch(const std::exception &error)
	{
		std::cerr << "There's no number " << toFind << " in the container" << std::endl;
	}
}

#endif
