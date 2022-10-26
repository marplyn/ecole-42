#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int value;
			static const int fractionalBits = 8;
	public:
			Fixed(); // дефолтный конструктор
			Fixed(const Fixed &original); // конструктор копирования
			Fixed& operator = (const Fixed &original); // перегрузка оператора присваивания
			~Fixed(); // деструктор

			int getRawBits(void) const;
			void setRawBits(int const raw);
};

#endif