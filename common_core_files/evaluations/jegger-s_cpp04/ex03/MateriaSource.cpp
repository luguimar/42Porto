#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->skills[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src){
	std::cout << "MateriaSource copy constructor called." << std::endl;
	*this = src;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &rhs){
	std::cout << "MateriaSource copy operator assignment called." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!rhs.getSkill(i))
				this->skills[i] = NULL;
			else
				this->skills[i] = rhs.getSkill(i)->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->skills[i])
		{
			delete this->skills[i];
		 	this->skills[i] = NULL;
		}
	}
}

AMateria*	MateriaSource::getSkill(int i) const {
	if (i >= 0 && i <= 4)	
		return this->skills[i];
	return NULL;
}


void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (!this->skills[i])
		{
			this->skills[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (!this->skills[i]->getType().compare(type))
			return this->skills[i]->clone();
	}
	return 0;
}