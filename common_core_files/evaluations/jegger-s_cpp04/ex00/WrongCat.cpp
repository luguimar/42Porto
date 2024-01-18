#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << this->type << " destructor called" << std::endl;
}

void    WrongCat::makeSound(void) const {
    std::cout << "MIAAAAAAU" << std::endl;
}