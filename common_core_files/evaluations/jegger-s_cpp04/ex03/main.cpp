#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void) 
{
	{
		std::cout << "** Testing Inventory **" << std::endl << std::endl;

		Ice			*ice = new Ice();
		Ice			*ice2 = new Ice();
		Cure		*cure = new Cure();
		Cure		*cure2 = new Cure();
		Cure		*test = new Cure();
		
		std::cout << std::endl;
		
		Character	*char1 = new Character("KARL");

		std::cout << std::endl;

		std::cout << ice->getType() << " - " << ice << std::endl;
		std::cout << ice2->getType() << " - " << ice2 << std::endl;
		std::cout << cure->getType() << " - " << cure << std::endl;
		std::cout << cure2->getType() << " - " << cure2 << std::endl << std::endl;

		char1->equip(ice);
		char1->equip(ice2);
		char1->equip(cure);
		char1->equip(cure2);
		
		//Testing Full Inverntory
		char1->equip(test);
		std::cout << char1->getInventory(5) << std::endl;

		std::cout << "Char: " << char1->getName() << std::endl << std::endl;

		std::cout << "Inventory" << std::endl;
		for (int i = 0; i < 4; i++)	{
			std::cout << char1->getInventory(i)->getType() << " - ";
			std::cout << char1->getInventory(i) << std::endl;
		}
		
		char1->unequip(2);
		
		std::cout << std::endl;
		std::cout << "Materia [2] unequiped" << std::endl;
		for (int i = 0; i < 4; i++)	{
			std::cout << char1->getInventory(i) << std::endl;
		}

		delete test;
		delete cure;
		delete char1;
		std::cout << std::endl;
		std::cout << "*************************************" << std::endl << std::endl;
	}
	{
		IMateriaSource* src = new MateriaSource();

		std::cout << std::endl;
		src->learnMateria(new Ice());
		std::cout << std::endl;
		src->learnMateria(new Cure());
		std::cout << std::endl;
		
		ICharacter* me = new Character("me");
		std::cout << std::endl;
		
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		std::cout << std::endl;
		me->use(0, *bob);
		std::cout << std::endl;
		me->use(1, *bob);
		std::cout << std::endl;
		
		//Texting an unequiped materia;
		me->use(2, *bob);
		me->unequip(2);


		delete bob;
		delete me;
		delete src;
	}
}