#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] default constructor called\n";
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "[WrongAnimal] copy constructor called\n";
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "[WrongAnimal] copy assignment operator called\n";
	if (&src != this)
		type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << type << " moos\n";
}

std::string WrongAnimal::getType() const
{
	return (type);
}