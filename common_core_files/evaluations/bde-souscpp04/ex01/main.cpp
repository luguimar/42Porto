/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:55:05 by bde-sous          #+#    #+#             */
/*   Updated: 2023/12/08 23:40:50 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

/*int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog("Faisca");
		const Animal* i = new Cat("Tete");
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete(i);
		delete(j);
		delete(meta);
	}
	std::cout << "---------------------------------------------" << std::endl;
}*/

 int main()
 {
 	const Animal* j[10];

 	for (int i = 0; i < 5; i++)
 		j[i] = new Dog("Tobias");
 	for (int i = 5; i < 10; i++)
 		j[i] = new Cat("Tete");
 	for (int i = 0; i < 10; i++)
 		delete(j[i]);
	return 0;
}
