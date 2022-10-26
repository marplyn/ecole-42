#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
			std::string name;
			Weapon *weapon;
	public:
			HumanB(std::string name);
			void setWeapon(Weapon &weapon);
			void attack();
};

#endif