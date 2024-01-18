#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure default constructor called." << std::endl; 
	this->type = "cure";
}

Cure::Cure(std::string const &type) : AMateria(type) {
	std::cout << "Cure constructor called." << std::endl; 
	this->type = "cure";
}

Cure::Cure(const Cure &src) : AMateria(src){
	std::cout << "Cure copy constructor called." << std::endl; 
	*this = src;
}

Cure& Cure::operator=(Cure const &rhs) {
	std::cout << "Cure copy assignment operator called." << std::endl;
	if (this != &rhs)
		type = rhs.type;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called." << std::endl;
}

std::string const & Cure::getType() const {
	return type;
}

Cure* Cure::clone() const {
	Cure	*clone = new Cure();
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() \
	<< "'s wounds *" << std::endl;
}