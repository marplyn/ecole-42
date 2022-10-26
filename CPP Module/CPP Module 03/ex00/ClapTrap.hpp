#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
			std::string name;
			int hitPoints;
			int energyPoints;
			int attackDamage;
	public:
			ClapTrap(); // дефолтный конструктор
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &original); // конструктор копирования
			ClapTrap& operator = (const ClapTrap &original); // перегрузка оператора присваивания
			~ClapTrap(); // деструктор

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);

			std::string getName() const;
			unsigned int getHitPoints() const;
			unsigned int getEnergyPoints() const;
			unsigned int getAttackDamage() const;
};

#endif