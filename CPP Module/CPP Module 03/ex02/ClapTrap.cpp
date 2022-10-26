#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called\n";
	name = "[Default]";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap name constructor called\n";
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << "Copy constructor called\n";
	*this = original;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	std::cout << "Copy assignment operator called\n";
	name = original.getName();
	hitPoints = original.getHitPoints();
	energyPoints = original.getEnergyPoints();
	attackDamage = original.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

std::string ClapTrap::getName() const
{
	return (name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (getEnergyPoints() == 0 || getHitPoints() == 0)
	{
		std::cout << "ClapTrap " << getName() << " can't do anything!\n";
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << getName() << " attacks " << target << \
	", causing " << getAttackDamage() << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() <= amount)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << getName() << " is dead now!\n";
	}
	else
	{
		std::cout << "ClapTrap " << getName() << " took " << amount << \
    " points of damage!\n";
		hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() == 0 || getHitPoints() == 0)
	{
		std::cout << "ClapTrap " << getName() << " can't repair himself!\n";
		return ;
	}
	std::cout << "ClapTrap " << getName() << " repaired " << amount << \
	" points!\n";
	hitPoints += amount;
	energyPoints--;
}
