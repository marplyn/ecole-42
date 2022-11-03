#include "easyfind.hpp"

int main(void)
{
	int SIZE = 10;

	std::vector<int> intVector(SIZE);

	std::cout << "Vector: [ ";
	for (int i = 0; i < SIZE; i++)
	{
		intVector[i] = i;
		std::cout << intVector[i] << " "; 
	}
	std::cout << "]\n";

	easyfind(intVector, 3);
	
	try
	{
		easyfind(intVector, 42);	
	}
	catch (std::exception & e)
	{
		std::cerr << "42 is not in this container\n";	
	}

	return (0);
}