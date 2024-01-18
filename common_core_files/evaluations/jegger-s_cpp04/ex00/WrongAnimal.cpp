#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    type = "WrongAnimal";
    std::cout << this->type << "Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
    this->type = type;
    std::cout << "WrongAnimal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal making wrong sounds" << std::endl;
}

std::string    WrongAnimal::getType(void) const {
    return this->type;
}