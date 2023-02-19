#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

class Animal {

public:
	Animal(void);
	Animal(const Animal& animal);
	~Animal(void);

	Animal& operator=(const Animal& animal);

	virtual const std::string&	getType(void) const;
	virtual void				makeSound(void) const;

protected:
	std::string	type;

};

#endif