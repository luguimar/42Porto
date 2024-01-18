#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string.h>

class	Dog : public AAnimal {

private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &src);
	Dog&	operator=(const Dog &rhs);
	virtual ~Dog();

	void		makeSound(void) const;
	std::string	getType(void) const;
	Brain*		getBrain(void) const;
};

#endif