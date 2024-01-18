#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor called." << std::endl; 
	type = "Mammal";
}

AAnimal::AAnimal(const AAnimal &src){
	std::cout << "AAnimal copy constructor called." << std::endl; 
	*this = src;
}

AAnimal&	AAnimal::operator=(const AAnimal &rhs){
	std::cout << "AAnimal copy assignment operator called." << std::endl; 
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called." << std::endl; 
}

std::string	AAnimal::getType(void) const{
	return type;
}

void	AAnimal::makeSound(void) const{
	std::cout << "The AAnimal " << type << " is making noise." << std::endl; 
}
