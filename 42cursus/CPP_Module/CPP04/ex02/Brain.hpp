#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

class Brain {

public:
	Brain(void);
	Brain(const Brain& brain);
	~Brain(void);

	Brain& operator=(const Brain& brain);

	void	addIdea(const std::string& idea);
	void	printIdeas(void) const;
	void	removeIdea(void);

private:
	std::string		ideas[100];
	unsigned int	count;

};

#endif