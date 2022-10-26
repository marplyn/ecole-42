#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
			std::string	name;
	public:
			void announce();
			void setZombieName(std::string name);
			Zombie(std::string name);
			Zombie();
			~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif