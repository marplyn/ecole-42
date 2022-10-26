#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string name);
			FragTrap (const FragTrap &original);
			FragTrap& operator = (FragTrap const &original);
			~FragTrap();

			void highFivesGuys(void);
};

#endif