#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

class Animal {

public:
	Animal(void);
	Animal(const Animal& animal);
	virtual ~Animal(void);

	Animal& operator=(const Animal& animal);

	const std::string&	getType(void) const;
	virtual void		makeSound(void) const = 0;

protected:
	std::string	type;

};

#endif