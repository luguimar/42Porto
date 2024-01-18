#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		const Animal*	meta = new Animal();
		const Animal*	cat = new Cat();
		const Animal*	dog = new Dog();


		std::cout << std::endl;
		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		std::cout << std::endl;

		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		std::cout << std::endl;

		std::cout << dog->getType() << std::endl;
		dog->makeSound();
		std::cout << std::endl;

		delete meta;
		delete cat;
		delete dog;
	}
	{
		std::cout << std::endl;
		const WrongAnimal* wrong = new WrongAnimal();
	    const WrongAnimal* wrongCat = new WrongCat();
		
		std::cout << std::endl;

	    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
	    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
		
		std::cout << std::endl;
	    
	    wrong->makeSound();
	    wrongCat->makeSound();

		std::cout << std::endl;
	    delete  wrong;
	    delete  wrongCat;
	}

}