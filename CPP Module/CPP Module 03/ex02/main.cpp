#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		FragTrap robotOne("Robot1");
		robotOne.attack("Robot2");
		robotOne.takeDamage(6);
		robotOne.beRepaired(4);
		robotOne.takeDamage(3);
		robotOne.highFivesGuys();
		robotOne.beRepaired(8);
		robotOne.takeDamage(17);
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		ScavTrap robotTwo("Robot1337");
		robotTwo.attack("Robot42");
		robotTwo.takeDamage(6);
		robotTwo.beRepaired(4);
		robotTwo.takeDamage(3);
		robotTwo.guardGate();
		robotTwo.beRepaired(8);
		robotTwo.takeDamage(17);
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