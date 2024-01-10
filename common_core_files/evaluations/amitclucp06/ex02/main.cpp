/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:09:16 by amitcul           #+#    #+#             */
/*   Updated: 2023/09/16 13:53:15 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void) {
	std::size_t obj_id = std::rand() % 3;

	switch (obj_id)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>( p );
		std::cout << "A" << std::endl;
		(void) a;
	} catch (const std::exception& e) {
	}

	try {
		B& b = dynamic_cast< B& >( p );
		std::cout << "B" << std::endl;
		(void) b;
	} catch (const std::exception& e ) {
	}

	try {
		C& c = dynamic_cast< C& >( p );
		std::cout << "C" << std::endl;
		(void) c;
	} catch (const std::exception& e ) {
	}
}


int main() {
	std::srand(std::time(0));

	Base* a = generate(); // C
	Base* b = generate();  // A
	Base* c = generate(); // A

	std::cout << "a* = ";
	identify(a);

	std::cout << "a& = ";
	identify(*a);
	std::cout << std::endl;

	std::cout << "b* = ";
	identify(b);

	std::cout << "b& = ";
	identify(*b);
	std::cout << std::endl;

	std::cout << "c* = ";
	identify(c);

	std::cout << "c& = ";
	identify(*c);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;

	return 0;
}
