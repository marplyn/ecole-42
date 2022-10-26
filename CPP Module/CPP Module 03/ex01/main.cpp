#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
	ScavTrap robotOne("Robot1");
	robotOne.attack("Robot42");
	robotOne.takeDamage(6);
	robotOne.beRepaired(4);
	robotOne.takeDamage(3);
	robotOne.guardGate();
	robotOne.beRepaired(8);
	robotOne.takeDamage(17);
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		ClapTrap robotThree("Bob");
		robotThree.attack("Tom");
		robotThree.takeDamage(6);
		robotThree.beRepaired(4);
		robotThree.takeDamage(3);
		robotThree.beRepaired(8);
		robotThree.takeDamage(17);
	}
	return (0);
}