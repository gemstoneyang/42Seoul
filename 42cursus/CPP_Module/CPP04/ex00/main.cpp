#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal*	animal = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();

	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	animal->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;

	std::cout << "\n--------------\n" << std::endl;

	const WrongAnimal*	wanimal = new WrongAnimal();
	const WrongAnimal*	wcat = new WrongCat();

	std::cout << std::endl;

	std::cout << wanimal->getType() << " " << std::endl;
	wanimal->makeSound();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound();

	std::cout << std::endl;

	delete wanimal;
	delete wcat;

	return 0;
}