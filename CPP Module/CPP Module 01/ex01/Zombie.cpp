#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::setZombieName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead!\n";
}

Zombie::Zombie()
{
	std::cout << "<default> BraiiiiiiinnnzzzZ...\n";
}