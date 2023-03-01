#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat: public Animal {

public:
	Cat(void);
	Cat(const Cat &cat);
	~Cat(void);

	Cat& operator=(const Cat& cat);

	void	makeSound(void) const;

private:

};

#endif