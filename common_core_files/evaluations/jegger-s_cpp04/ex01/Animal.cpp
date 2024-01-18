#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called." << std::endl; 
	type = "Mammal";
}

Animal::Animal(const Animal &src){
	std::cout << "Animal copy constructor called." << std::endl; 
	*this = src;
}

Animal&	Animal::operator=(const Animal &rhs){
	std::cout << "Animal copy assignment operator called." << std::endl; 
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called." << std::endl; 
}

std::string	Animal::getType(void) const{
	return type;
}

void	Animal::makeSound(void) const{
	std::cout << "The Animal " << type << " is making noise." << std::endl; 
}
