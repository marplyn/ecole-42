#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(Fixed(5.05f) + Fixed(5.1f));
	Fixed d(Fixed(15.3f) - Fixed(5.1f));
	Fixed e(10);
	Fixed f(10);

//	std::cout << "a: " << a << '\n';
//	std::cout << "b: " << b << '\n';
//	std::cout << "c: " << c << '\n';
//	std::cout << "d: " << d << '\n';
//
//	std::cout << "comparison test\n";
//	std::cout << (b > c) << '\n';
//	std::cout << (b < c) << '\n';
//	std::cout << (b >= c) << '\n';
//	std::cout << (b <= c) << '\n';
//	std::cout << (b == c) << '\n';
//	std::cout << (b != c) << '\n';
//	std::cout << (e == f) << '\n';
//	std::cout << (e != f) << '\n';
//
//	std::cout << "increment / decrement test\n";
//	std::cout << ++e << '\n';
//	std::cout << e << '\n';
//	std::cout << e++ << '\n';
//	std::cout << e << '\n';
//	std::cout << --e << '\n';
//	std::cout << e << '\n';
//	std::cout << e-- << '\n';
//	std::cout << e << '\n';

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return (0);
}