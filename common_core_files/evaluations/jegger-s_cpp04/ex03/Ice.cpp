#include "Ice.hpp"

Ice::Ice() {
	std::cout << "Ice default constructor called." << std::endl; 
	this->type = "ice";
}

Ice::Ice(std::string const &type) : AMateria(type) {
	std::cout << "Ice constructor called." << std::endl; 
	this->type = "ice";
}

Ice::Ice(const Ice &src) : AMateria(src){
	std::cout << "Ice copy constructor called." << std::endl; 
	*this = src;
}

Ice& Ice::operator=(Ice const &rhs) {
	std::cout << "Ice copy assignment operator called." << std::endl;
	if (this != &rhs)
		type = rhs.type;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}

std::string const & Ice::getType() const {
	return type;
}

Ice* Ice::clone() const {
	Ice	*clone = new Ice();
	return clone;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " \
	<< target.getName() << " *" << std::endl;
}