#include "Character.hpp"

Character::Character() {
	std::cout << "Character default constructor called." << std::endl;
	this->initInventory();
}

Character::Character(std::string name) {
	std::cout << "Character constructor called." << std::endl;
	this->name = name;
	this->initInventory();
}

Character::Character(const Character &src) {
	std::cout << "Character copy constructor called." << std::endl;
	this->initInventory();
	*this = src;
}

Character& Character::operator=(const Character &rhs) {
	std::cout << "Character copy assigment operator called." << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->freeInventory();
		for (int i = 0; i < 4; i++)
		{
			if (!rhs.getInventory(i))
				this->inventory[i] = NULL;
			else
				this->inventory[i] = rhs.getInventory(i)->clone();
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called." << std::endl;
	this->freeInventory();
}

//GETS
std::string const &Character::getName() const {
	return name;
}

void	Character::initInventory(void) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

void	Character::freeInventory(void) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

AMateria*	Character::getInventory(int	i) const {
	if (i >= 0 && i <= 4)
		return this->inventory[i];
	return NULL;
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 4)
		if (this->inventory[idx])
			this->inventory[idx] = NULL;
	return ;
}
void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 4)
		if (this->inventory[idx])
			this->inventory[idx]->use(target);
	return ;
}