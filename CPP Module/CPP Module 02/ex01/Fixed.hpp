#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
			int value;
			static const int fractionalBits = 8;
	public:
			Fixed();
			Fixed(const int n);
			Fixed(const float n);
			Fixed(const Fixed &original);
			Fixed& operator = (const Fixed &original);
			~Fixed();

			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat(void) const;
			int toInt(void) const;
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed &fixed);

#endif