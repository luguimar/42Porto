#ifndef	ICE_HPP
#define	ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

public:
	Ice();
	Ice(std::string const &type);
	Ice(const Ice&);
	Ice& operator=(Ice const &rhs);
	~Ice();

	std::string const & getType() const; //Returns the materia type
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif