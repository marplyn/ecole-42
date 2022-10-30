#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] default constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "[Dog] copy constructor called\n";
	*this = src;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "[Dog] copy assignment operator called\n";
	type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << type << " barks\n";
}