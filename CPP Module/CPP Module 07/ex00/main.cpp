#include "whatever.hpp"

class Awesome
{
	public:
			Awesome(): _n(0) {}
			Awesome(int n) : _n(n) {}
			bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
			bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
			bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
			bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
			bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
			bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
			int get() const { return this->_n; }
	private:
			int _n;
};

int main(void) 
{
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << "\n";
	::swap(a, b);
	std::cout << "swapping: " << "a = " << a << ", b = " << b << "\n";
	std::cout << "min(a, b) = " << ::min(a, b) << "\n";
	std::cout << "max(a, b) = " << ::max(a, b) << "\n";

	std::cout << "---------------------\n";

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << "\n";
	::swap(c, d);
	std::cout << "swapping: " << "c = " << c << ", d = " << d <<  "\n";
	std::cout << "min(c, d) = " << ::min(c, d) <<  "\n";
	std::cout << "max(c, d) = " << ::max(c, d) <<  "\n";

	std::cout << "---------------------\n";

	Awesome g(6);
	Awesome h(10);
	std::cout << "g = " << g.get() << ", h = " << h.get() <<  "\n";
	::swap(g, h);
	std::cout << "swapping: " << "g = " << g.get() << ", h = " << h.get() << "\n";
	std::cout << "min(g, h) = " << ::min(g, h).get() <<  "\n";
	std::cout << "max(g, h) = " << ::max(g, h).get() <<  "\n";

	return (0);
}