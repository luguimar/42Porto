#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat constructor called." << std::endl; 
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->brain = new Brain;
	*this = src;
}

Cat&	Cat::operator=(const Cat &rhs){
	std::cout << "Cat copy assignment operator called." << std::endl; 
	if (this != &rhs)
	{
		this->type = rhs.type;
		(*this->brain) = (*rhs.brain);
	}
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called." << std::endl;
}

std::string	Cat::getType(void) const{
	return type;
}

void	Cat::makeSound(void) const{
	std::cout << "The Animal " << type << " MIAAAAAAAAAAAAAAU." << std::endl; 
}

Brain*	Cat::getBrain(void) const{
	return brain;
}
