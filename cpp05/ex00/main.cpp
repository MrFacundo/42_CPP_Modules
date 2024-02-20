/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:44 by facu              #+#    #+#             */
/*   Updated: 2024/02/20 15:03:04 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal dog2 = Dog();
	const WrongAnimal* wrongCat = new WrongCat();
	
	animal->printType();
	animal->makeSound(); //outputs the animal sound
	cat->printType();
	cat->makeSound(); //outputs the cat sound
	dog->printType();
	dog->makeSound(); //outputs the dog sound
	dog2.printType();
	dog2.makeSound(); //outputs the animal sound because of object slicing
	wrongCat->printType();
	wrongCat->makeSound(); //outputs the animal sound because makeSound is not virtual
	delete animal;
	delete cat;
	delete dog;
	delete wrongCat;
	return 0;
}