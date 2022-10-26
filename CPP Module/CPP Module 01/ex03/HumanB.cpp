#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = nullptr;
}

void HumanB::attack()
{
	if (weapon != nullptr)
		std::cout << name << " attacks with their " << weapon->getType() << '\n';
	else
		std::cout << name << " has no weapon\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}