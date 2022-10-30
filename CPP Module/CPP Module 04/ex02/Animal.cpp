#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] constructor called\n";
	type = "Animal";
}

Animal::Animal(const Animal &src)
{
	std::cout << "[Animal] copy constructor called\n";
	*this = src;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "[Animal] copy assignment operator called\n";
	if (&src != this)
		type = src.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] destructor called\n";
}

void Animal::makeSound() const
{
	std::cout << type << " default sound\n";
}

std::string Animal::getType() const
{
	return (type);
}