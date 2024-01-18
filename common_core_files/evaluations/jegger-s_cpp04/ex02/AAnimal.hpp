#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class	AAnimal {

protected:
	std::string	type;

public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal&	operator=(const AAnimal &rhs);
	virtual	~AAnimal();

	virtual void	makeSound(void) const = 0;
	virtual std::string	getType(void) const;
};

#endif