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

	const std::string&	getType(void);
	void				makeSound(void);

protected:
	std::string	type;

};

#endif