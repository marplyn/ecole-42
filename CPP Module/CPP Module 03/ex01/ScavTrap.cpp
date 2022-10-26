#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	name = "[Default]";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap name constructor called\n";
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original)
{
	std::cout << "Copy constructor called\n";
	*this = original;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
	std::cout << "Copy assignment operator called\n";
	name = original.getName();
	hitPoints = original.getHitPoints();
	energyPoints = original.getEnergyPoints();
	attackDamage = original.getAttackDamage();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() == 0 || getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " can't do anything!\n";
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << getName() << " attacks " << target << \
	", causing " << getAttackDamage() << " points of damage!\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode\n";
}