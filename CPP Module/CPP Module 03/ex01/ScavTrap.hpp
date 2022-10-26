#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
			ScavTrap(); 
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &original);
			ScavTrap& operator = (const ScavTrap &original);
			~ScavTrap();

			void attack(const std::string& target);
			void guardGate();
};

#endif