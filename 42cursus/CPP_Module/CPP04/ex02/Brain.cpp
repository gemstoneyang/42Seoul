#include <iostream>
#include "Brain.hpp"

// Constructor & Destructor
Brain::Brain(void) {
	std::cout << "Brain: Default constructor called" << std::endl;

	count = 0;
}

Brain::Brain(const Brain& brain) {
	std::cout << "Brain: Copy constructor called" << std::endl;

	for (unsigned int i = 0; i < brain.count; i++)
		this->ideas[i] = brain.ideas[i];
	this->count = brain.count;
}

Brain::~Brain(void) {
	std::cout << "Brain: Destructor called" << std::endl;
}


// Operator Overloading
Brain& Brain::operator=(const Brain& brain) {
	std::cout << "Brain: Copy assignment operator called" << std::endl;

	for (unsigned int i = 0; i < brain.count; i++)
		this->ideas[i] = brain.ideas[i];
	this->count = brain.count;

	return *this;
}


// Member Function
void	Brain::addIdea(const std::string& idea) {
	if (count == 100) {
		std::cout << "My brain is full" << std::endl;
		return;
	}

	ideas[count] = idea;
	count++;
}

void	Brain::printIdeas(void) const {
	if (count == 0) {
		std::cout << "I have no idea" << std::endl;
		return;
	}

	for (unsigned int i = 0; i < count; i++) {
		std::cout << i << ". " << ideas[i] << std::endl;
	}
}

void	Brain::removeIdea(void) {
	if (count == 0) {
		std::cout << "I have no idea" << std::endl;
		return;
	}

	count--;
}
