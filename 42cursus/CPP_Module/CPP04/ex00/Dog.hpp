#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog: public Animal {

public:
	Dog(void);
	Dog(const Dog &dog);
	~Dog(void);

	Dog& operator=(const Dog& dog);

	const std::string&	getType(void) const;
	void				makeSound(void) const;

private:

};

#endif