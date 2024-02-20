/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/19 16:01:02 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing default constructors and destructors" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing copy constructors" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	{
		Dog dog1;
		dog1.setIdea(0, "This is dog1's idea");
		Dog dog2(dog1);
		Cat cat1;
		cat1.setIdea(0, "This is cat1's idea");
		Cat cat2(cat1);
		dog2.printIdeas();
		cat2.printIdeas();
		std::cout << dog2.getType() << std::endl;
		dog2.makeSound();
		std::cout << cat2.getType() << std::endl;
		cat2.makeSound();
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing assignment operators" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	{
		Dog dog3;
		dog3.setIdea(0, "This is dog3's idea");
		Dog dog4 = dog3;
		dog4.setIdea(1, "This is dog4's idea");
		dog3 = dog4;
		dog3.printIdeas();
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing deep copy" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	{
		Dog dogOriginal;
		dogOriginal.setIdea(0, "Original dog's idea");
		Dog dogCopy(dogOriginal);
		dogCopy.setIdea(0, "Copied dog's modified idea");
		if (dogOriginal.getIdea(0) == dogCopy.getIdea(0))
		{
			std::cout << "The changes in the copied dog affected the original dog. Shallow copy detected." << std::endl;
		}
		else
		{
			std::cout << "The changes in the copied dog did not affect the original dog. Deep copy successful." << std::endl;
		}
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Testing Animals array" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	const int n = 4;
	Animal *animals[n];
	for (int i = 0; i < n / 2; i++)
		animals[i] = new Dog();
	for (int i = n / 2; i < n; i++)
		animals[i] = new Cat();
	for (int i = 0; i < n; i++)
		animals[i]->makeSound();
	for (int i = 0; i < n; i++)
		delete animals[i];
	return 0;
}