#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"

void	leaksCheck(void) {
	system("leaks zombie_horde | grep leaks");
}

int	main(void) {
	atexit(leaksCheck);

	const int N = 5;
	Zombie*	horde = zombieHorde(N, "zombie");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}
