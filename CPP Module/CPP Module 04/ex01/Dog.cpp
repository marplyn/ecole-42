#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] default constructor called\n";
	type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog &src)
{
	std::cout << "[Dog] copy constructor called\n";
	*this = src;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "[Dog] copy assignment operator called\n";
	if (&src != this)
		*brain = *src.brain;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called\n";
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << type << " barks\n";
}

Brain* Dog::getBrain() const
{
	return brain;
}