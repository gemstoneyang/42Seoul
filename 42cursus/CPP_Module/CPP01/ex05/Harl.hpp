#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

class Harl {

public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level);

	typedef void (Harl::*funcptr)(void);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	

};

#endif