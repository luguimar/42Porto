#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called." << std::endl; 
	type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat copy constructor called." << std::endl; 
	*this = src;
}

Cat&	Cat::operator=(const Cat &rhs){
	std::cout << "Cat copy assignment operator called." << std::endl; 
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called." << std::endl; 
}

std::string	Cat::getType(void) const{
	return type;
}

void	Cat::makeSound(void) const{
	std::cout << "The Animal " << type << " MIAAAAAAAAAAAAAAU." << std::endl; 
}
