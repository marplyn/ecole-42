#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
			std::string type;
	public:
			Animal();
			virtual ~Animal();
			Animal(const Animal &src);
			Animal& operator=(const Animal &src);
			virtual void makeSound() const;
			std::string getType() const;
};

#endif