#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called\n";
	*this = original;
}

Fixed& Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called\n";
	value = original.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}