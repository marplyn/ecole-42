#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called\n";
	name = "[Default]";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap name constructor called\n";
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &original)
{
	std::cout << "Copy constructor called\n";
	*this = original;
}

FragTrap& FragTrap::operator=(const FragTrap &original)
{
	std::cout << "Copy assignment operator called\n";
	name = original.getName();
	hitPoints = original.getHitPoints();
	energyPoints = original.getEnergyPoints();
	attackDamage = original.getAttackDamage();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " gives high five to everyone!\n";
}