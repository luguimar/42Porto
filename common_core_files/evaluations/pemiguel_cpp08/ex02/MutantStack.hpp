/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:56:12 by pemiguel          #+#    #+#             */
/*   Updated: 2023/06/14 13:17:55 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>

/*This is the template for std::stack class, see in "https://en.cppreference.com/w/cpp/container/stack"*/
/*Also inherit from std::stack it self to use their functions (push(), pop() etc...)*/
template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack &operator = (const MutantStack& other);
	typedef typename Container::iterator iterator; //using iterator that is already in std::deque
	/*In both of this function, we use 'this->c' to access to underlaying cointainer (std::deque) which provides the begin(), end() functions*/
	typename Container::iterator begin()
	{
		return (this->c.begin());
	}

	typename Container::iterator end()
	{
		return (this->c.end());
	}
};

template <typename T, class Container>
MutantStack<T, Container>::MutantStack()
{
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator = (const MutantStack& other)
{
	//Call the operator overloading of Container class(std::deque)
	std::stack<T, Container>::operator = (other);
	return (*this);
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
{
	*this = other;
}

#endif
