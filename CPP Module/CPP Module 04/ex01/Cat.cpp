#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] default constructor called\n";
	type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat &src)
{
	std::cout << "[Cat] copy constructor called\n";
	*this = src;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "[Cat] copy assignment operator called\n";
	if (&src != this)
		*brain = *src.brain;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor called\n";
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << type << " meows\n";
}

Brain* Cat::getBrain() const
{
	return brain;
}