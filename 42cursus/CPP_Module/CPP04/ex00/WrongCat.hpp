#pragma once
#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

public:
	WrongCat(void);
	WrongCat(const WrongCat &wrongCat);
	~WrongCat(void);

	WrongCat& operator=(const WrongCat& wrongCat);

	void	makeSound(void) const;

private:

};

#endif