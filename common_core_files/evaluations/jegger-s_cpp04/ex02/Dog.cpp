#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog constructor called." << std::endl; 
	type = "Dog";
	brain = new Brain();	
}

Dog::Dog(const Dog &src) : AAnimal(src) {
	std::cout << "Dog copy constructor called." << std::endl; 
	this->brain = new Brain;
	*this = src;
}

Dog&	Dog::operator=(const Dog &rhs){
	std::cout << "Dog copy assignment operator called." << std::endl; 
	if (this != &rhs)
	{
		this->type = rhs.type;
		(*this->brain) = (*rhs.brain);
	}
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called." << std::endl; 
}

std::string	Dog::getType(void) const{
	return type;
}

Brain*	Dog::getBrain(void) const{
	return brain;
}

void	Dog::makeSound(void) const{
	std::cout << "The Animal " << type << " is barking at the moon." << std::endl; 
}
