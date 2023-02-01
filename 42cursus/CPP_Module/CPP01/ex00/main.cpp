#include <iostream>
#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombie = newZombie("HeapZombie");

	zombie->announce();

	randomChump("StackZombie");

	delete zombie;
	return 0;
}