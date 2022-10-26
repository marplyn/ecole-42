#include "Zombie.hpp"
#include <cstdio>

int main()
{
	Zombie *bob;
	Zombie *matt;

	bob = newZombie("Bob");
	bob->announce();

	matt = newZombie("Matt");
	matt->announce();

	randomChump("Anna");
	randomChump("Patric");

	delete bob;
	delete matt;

	return (0);
}