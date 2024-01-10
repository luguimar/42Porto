/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:54:56 by pemiguel          #+#    #+#             */
/*   Updated: 2023/06/14 13:19:56 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
int main()
{
	std::cout << "MutantStack with integers" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Last element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Numbers in Stack" << std::endl;
	std::cout << "{";
	while (it != ite)
	{
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ", ";
		++it;
	}
	std::cout << "}" << std::endl;
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << "Using std::list" << std::endl;
    std::list< int > lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Last element: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Stack size: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    std::cout << "{";
	while (lst_it != lst_ite)
	{
		while (true)
		{
		std::cout << *lst_it;
		if (++lst_it != lst_ite)
			std::cout << ", ";
		else
			break;
		}
	}
	std::cout << "}" << std::endl;
    std::list<int> l(lst);

	std::cout << std::endl;

	std::cout << "MutantStack with chars" << std::endl;
	MutantStack<char> letters;
	letters.push('p');
	letters.push('d');
	std::cout << "First element: " << letters.top() << std::endl;
	letters.pop();
	letters.push('e');
	letters.push('d');
	letters.push('r');
	letters.push('o');
	MutantStack<char>::iterator it2 = letters.begin();
	MutantStack<char>::iterator ite2 = letters.end();
	while (it2 != ite2)
	{
		std::cout << *it2;
		++it2;
	}
	std::stack<char> s2(letters);
	return (0);
}
