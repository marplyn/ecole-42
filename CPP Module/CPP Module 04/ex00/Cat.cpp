#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] default constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "[Cat] copy constructor called\n";
	*this = src;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "[Cat] copy assignment operator called\n";
	type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << type << " meows\n";
}