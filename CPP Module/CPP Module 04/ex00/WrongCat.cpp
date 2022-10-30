#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WrongCat] default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "[WrongCat] copy constructor called\n";
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "[WrongCat] copy assignment operator called\n";
	type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << type << " sounds WrongMeow\n";
}