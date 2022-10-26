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

			bool operator>(const Fixed& original) const;
			bool operator<(const Fixed& original) const;
			bool operator>=(const Fixed& original) const;
			bool operator<=(const Fixed& original) const;
			bool operator==(const Fixed& original) const;
			bool operator!=(const Fixed& original) const;

			Fixed operator+(const Fixed& original) const;
			Fixed operator-(const Fixed& original) const;
			Fixed operator*(const Fixed& original) const;
			Fixed operator/(const Fixed& original) const;

			Fixed& operator++(); // pre-increment
			Fixed operator++(int); // post-increment
			Fixed& operator--(); // pre-decrement
			Fixed operator--(int); // post-decrement

			static Fixed& min(Fixed& a, Fixed& b);
			static const Fixed& min(const Fixed& a, const Fixed& b);
			static Fixed& max(Fixed& a, Fixed& b);
			static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed &fixed);

#endif