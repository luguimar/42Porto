#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria	*skills[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource&);
	MateriaSource&	operator=(const MateriaSource &rhs);
	~MateriaSource();
	void 		learnMateria(AMateria *m);
	AMateria*	getSkill(int i) const;
	AMateria* 	createMateria(std::string const & type);
};

#endif