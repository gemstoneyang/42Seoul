#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << "\n--------------\n" << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << "\n--------------\n" << std::endl;

	const Dog*	doggy = dynamic_cast<const Dog*>(dog);
	doggy->getBrain()->addIdea("I want to eat meat..");
	doggy->getBrain()->addIdea("I'm hungry!");
	doggy->getBrain()->printIdeas();

	doggy->getBrain()->removeIdea();
	doggy->getBrain()->printIdeas();

	doggy->getBrain()->removeIdea();
	doggy->getBrain()->printIdeas();

	std::cout << "\n--------------\n" << std::endl;

	const Dog*	mong = dynamic_cast<const Dog*>(dog);
	mong->getBrain()->addIdea("I want to eat meat..");
	mong->getBrain()->addIdea("I'm hungry!");
	
	const Dog*	poppy = new Dog();
	poppy = mong;
	poppy->getBrain()->printIdeas();

	delete poppy;

	std::cout << "\n--------------\n" << std::endl;

	delete meta;
	delete dog;
	delete cat;

	return 0;
}