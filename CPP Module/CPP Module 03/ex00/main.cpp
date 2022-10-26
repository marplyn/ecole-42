#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap dur("Robot1");

	dur.attack("Robot2");
	dur.takeDamage(6);
	dur.beRepaired(4);
	dur.takeDamage(3);
	dur.beRepaired(8);
	dur.takeDamage(17);
	return (0);
}