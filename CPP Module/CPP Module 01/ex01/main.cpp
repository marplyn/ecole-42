#include "Zombie.hpp"
#include <cstdio>

int main(void)
{
	int N = 10;
	Zombie* zombies = zombieHorde(N,"Zombie");

	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}