#ifndef	CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {

private:
	std::string	name;
	AMateria	*inventory[4];

public:
	Character();
	Character(std::string name);
	Character(const Character&);
	Character& operator=(const Character &rhs);
	~Character();
	//GETS
	std::string const & getName() const;
	AMateria*	getInventory(int i) const;

	void	initInventory(void);
	void	freeInventory(void);
	void 	equip(AMateria* m);
	void 	unequip(int idx);
	void 	use(int idx, ICharacter& target);
};

#endif