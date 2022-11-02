#include "iter.hpp"

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <typename T>
void print(T const & x) { std::cout << x << std::endl; return;}

int main(void)
{
	int arr1[] = {9, 8, 7, 6, 5};
	char arr2[] = {'H', 'E', 'L', 'L', 'O', ':', ')'};

	std::cout << "{9, 8, 7, 6, 5}:--------------------------\n";
	iter(arr1, 5, print);
	std::cout << "{'H', 'E', 'L', 'L', 'O', ':', ')'}:------\n";
	iter(arr2, 7, print);

	std::cout << "Awesome test:-----------------------------\n";
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);

	return (0);
}