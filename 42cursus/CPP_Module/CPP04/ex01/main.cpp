#include <iostream>
#include <stdlib.h>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	leaksCheck(void) {
	system("leaks ex01 | grep leaks");
}

int main(void)
{
	atexit(leaksCheck);

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

	const Dog*	doggy = new Dog();

	std::cout << std::endl;

	doggy->getBrain()->addIdea("I want to eat meat..");
	doggy->getBrain()->addIdea("I'm hungry!");
	doggy->getBrain()->printIdeas();

	std::cout << std::endl;

	doggy->getBrain()->removeIdea();
	doggy->getBrain()->printIdeas();

	std::cout << std::endl;

	doggy->getBrain()->removeIdea();
	doggy->getBrain()->printIdeas();

	std::cout << std::endl;

	delete doggy;

	std::cout << "\n--------------\n" << std::endl;

	Animal*	animals[10];

	std::cout << std::endl;
	
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "\n--------------\n" << std::endl;

	Dog	poppy;
	Dog	bobby;

	std::cout << std::endl;

	poppy.getBrain()->addIdea("I want to eat meat..");
	poppy.getBrain()->addIdea("I'm hungry!");
	poppy.getBrain()->printIdeas();

	std::cout << std::endl;
	
	bobby = poppy;
	bobby.getBrain()->printIdeas();

	std::cout << std::endl;

	return 0;
}