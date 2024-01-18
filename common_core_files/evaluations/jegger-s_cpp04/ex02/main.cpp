#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		const Dog*		dog = new Dog();
		std::cout << std::endl;
		const Dog*		dog2 = new Dog(*dog);
		std::cout << std::endl;
		const Cat*		cat = new Cat();
		std::cout << std::endl;
		Cat		cat2;
		std::cout << std::endl;

		//Get Brains Address
		std::cout << "Dog:  " << dog->getBrain() << std::endl;
		std::cout << "Dog2: " << dog2->getBrain() << std::endl;
		std::cout << "Cat: " << cat->getBrain() << std::endl;
		std::cout << "Cat2: " << cat2.getBrain() << std::endl;
		
		std::cout << std::endl;
		// Set Ideas
		dog->getBrain()->setIdea("Am I a dog 1?", 1);
		dog->getBrain()->setIdea("what a dog 1", 2);
		dog2->getBrain()->setIdea("Am I a dog 2?", 1);
		cat->getBrain()->setIdea("Am I a cat?", 1);
		cat2.getBrain()->setIdea("Am I a cat 2?", 1);
		// Get Ideas
		std::cout << "Dog:  " << dog->getBrain()->getIdea(1) << std::endl;
		std::cout << "Dog:  " << dog->getBrain()->getIdea(2) << std::endl;
		std::cout << "Dog2: " << dog2->getBrain()->getIdea(1) << std::endl;
		std::cout << "Cat: " << cat->getBrain()->getIdea(1) << std::endl;
		std::cout << "Cat2: " << cat2.getBrain()->getIdea(1) << std::endl;
		
		std::cout << std::endl;
		cat2 = *cat;
		std::cout << std::endl;
		//Get Brains Address
		std::cout << "Dog:  " << dog->getBrain() << std::endl;
		std::cout << "Dog2: " << dog2->getBrain() << std::endl;
		std::cout << "Cat: " << cat->getBrain() << std::endl;
		std::cout << "Cat2: " << cat2.getBrain() << std::endl;
		
		std::cout << std::endl;

		// Get Ideas
		std::cout << "Dog:  " << dog->getBrain()->getIdea(1) << std::endl;
		std::cout << "Dog:  " << dog->getBrain()->getIdea(2) << std::endl;
		std::cout << "Dog2: " << dog2->getBrain()->getIdea(1) << std::endl;
		std::cout << "Cat: " << cat->getBrain()->getIdea(1) << std::endl;
		std::cout << "Cat2: " << cat2.getBrain()->getIdea(1) << std::endl;

		std::cout << std::endl;

		delete dog;
		delete dog2;
		delete cat;
	}
	// {
	// 	//Trying to instantiate an Animal
	// 	AAnimal Animal;
	// }
}


