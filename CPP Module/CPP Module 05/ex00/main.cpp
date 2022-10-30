#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Thomas", 1337);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		Bureaucrat bureaucrat("Mark", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}	

	try
	{
		Bureaucrat bureaucrat("Bob", 1);
		bureaucrat.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat bureaucrat("Jake", 150);
		bureaucrat.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}