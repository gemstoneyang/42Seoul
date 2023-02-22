#pragma once
#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

class WrongAnimal {

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& wrongAnimal);
	virtual ~WrongAnimal(void);

	WrongAnimal& operator=(const WrongAnimal& wrongAnimal);

	const std::string&	getType(void) const;
	void				makeSound(void) const;

protected:
	std::string	type;

};

#endif