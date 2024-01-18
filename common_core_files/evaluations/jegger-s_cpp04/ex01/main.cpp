#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
	    const Animal* j = new Dog();
		std::cout << std::endl;
	    const Animal* i = new Cat();
		std::cout << std::endl;

	    delete j;
		std::cout << std::endl;
	    delete i;
		std::cout << std::endl;
	}
	{
		std::cout << "*********************************" << std::endl << std::endl;

	    Dog basic;
	    {
			std::cout << std::endl;
	        
			basic.getBrain()->setIdea("Basic Idea to temp", 0);

	        Dog tmp = basic;
			std::cout << std::endl;
	        Dog tmp2(basic);
			std::cout << std::endl;

			std::cout << basic.getBrain() << std::endl;
			std::cout << tmp.getBrain() << std::endl;
			std::cout << tmp2.getBrain() << std::endl << std::endl;


			std::cout << tmp.getBrain()->getIdea(0) << std::endl;


	    }
		std::cout << std::endl;
		std::cout << basic.getBrain() << std::endl;
		basic.getBrain()->setIdea("Basic Idea", 0);
		std::cout << basic.getBrain()->getIdea(0) << std::endl;
	}
	{
		std::cout << "*********************************" << std::endl;
		std::cout << std::endl;
	    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
		std::cout << std::endl;
	    for ( int i = 0; i < 4; i++ ) {
	        animals[i]->makeSound();
	        delete animals[i];
			std::cout << std::endl;
	    }
	}

    return 0;
}


