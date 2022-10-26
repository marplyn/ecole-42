#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	this->value = n << fractionalBits;
}


Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	this->value = roundf(n * (1 << fractionalBits));
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

std::ostream& operator<<(std::ostream& outputStream, const Fixed &fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}

float Fixed::toFloat(void) const
{
	float	n;

	n = float(this->value) / (1 << fractionalBits);
	return (n);
}

int Fixed::toInt(void) const
{
	int	n;

	n = this->value >> fractionalBits;
	return (n);
}


bool Fixed::operator>(const Fixed& original) const
{
	return value > original.value;
}

bool Fixed::operator<(const Fixed& original) const
{
	return value < original.value;
}

bool Fixed::operator>=(const Fixed& original) const
{
	return value >= original.value;
}

bool Fixed::operator<=(const Fixed& original) const
{
	return value <= original.value;
}

bool Fixed::operator==(const Fixed& original) const
{
	return value == original.value;
}

bool Fixed::operator!=(const Fixed& original) const
{
	return value != original.value;
}


Fixed Fixed::operator+(const Fixed& original) const
{
	return Fixed(this->toFloat() + original.toFloat());
}

Fixed Fixed::operator-(const Fixed& original) const
{
	return Fixed(this->toFloat() - original.toFloat());
}

Fixed Fixed::operator*(const Fixed& original) const
{
	return Fixed(this->toFloat() * original.toFloat());
}

Fixed Fixed::operator/(const Fixed& original) const
{
	return Fixed(this->toFloat() / original.toFloat());
}


Fixed& Fixed::operator++()
{
	++value;
	return *this;
}

Fixed& Fixed::operator--()
{
	--value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed original = *this;
	++value;
	return original;
}

Fixed Fixed::operator--(int)
{
	Fixed original = *this;
	--value;
	return original;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}
