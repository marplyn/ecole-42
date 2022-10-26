#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
			std::string name;
			int hitPoints;
			int energyPoints;
			int attackDamage;
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &original);
			ClapTrap& operator = (const ClapTrap &original);
			~ClapTrap(); 

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);

			std::string getName() const;
			unsigned int getHitPoints() const;
			unsigned int getEnergyPoints() const;
			unsigned int getAttackDamage() const;
};

#endif