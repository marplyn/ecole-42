#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		zombieHorde[i].setZombieName(name + '_' + std::to_string(i));
	return (zombieHorde);
}
