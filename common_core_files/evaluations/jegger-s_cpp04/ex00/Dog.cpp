#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called." << std::endl; 
	type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog copy constructor called." << std::endl; 
	*this = src;
}

Dog&	Dog::operator=(const Dog &rhs){
	std::cout << "Dog copy assignment operator called." << std::endl; 
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called." << std::endl; 
}

std::string	Dog::getType(void) const{
	return type;
}

void	Dog::makeSound(void) const{
	std::cout << "The Animal " << type << " is barking at the moon." << std::endl; 
}
