#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(){
	std::cout << "Materia default constructor called." << std::endl; 
}
AMateria::AMateria(std::string const &type){
	std::cout << "Materia constructor called." << std::endl; 
	this->type = type;
}

AMateria::AMateria(const AMateria &src){
	std::cout << "Materia copy constructor called." << std::endl; 
	*this = src;
}

AMateria& AMateria::operator=(AMateria const &rhs){
	std::cout << "Materia copy assignment operator called." << std::endl;
	if (this != &rhs)
		type = rhs.type;
	return *this;
}

AMateria::~AMateria(){
	std::cout << "Materia destructor called." << std::endl;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	(void) target;
}