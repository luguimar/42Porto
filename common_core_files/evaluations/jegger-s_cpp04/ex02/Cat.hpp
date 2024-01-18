#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class	Cat : public AAnimal {

private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &src);
	Cat&	operator=(const Cat &rhs);
	virtual ~Cat();

	void		makeSound(void) const;
	std::string	getType(void) const;
	Brain*		getBrain(void) const;
};

#endif