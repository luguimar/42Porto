#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called." << std::endl; 
}

Brain::Brain(const Brain &src){
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
}

Brain&	Brain::operator=(Brain const &rhs){
	std::cout << "Brain copy assignment operator called." << std::endl; 
	if (this != &rhs)
	{
	    for (int i = 0; i < 100; i++) {
	        this->ideas[i] = rhs.ideas[i];
	    }
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor called." << std::endl;
}

std::string	Brain::getIdea(unsigned int n){
	return this->ideas[n];
}
void		Brain::setIdea(std::string str, unsigned int n){
	this->ideas[n] = str;
}