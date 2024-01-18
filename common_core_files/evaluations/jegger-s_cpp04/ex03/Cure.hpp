#ifndef	CURE_HPP
#define	CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

public:
	Cure();
	Cure(std::string const &type);
	Cure(const Cure&);
	Cure& operator=(Cure const &rhs);
	~Cure();

	std::string const & getType() const; //Returns the materia type
	Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif