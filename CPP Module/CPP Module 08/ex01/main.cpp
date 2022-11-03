#include "Span.hpp"

int main()
{
	std::cout << "Subject test:-----------------------\n";
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Trying to add new to full:----------\n";
	try
	{
		Span sp = Span(3);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Adding numbers with push_back:++++++\n";
	try
	{
		std::vector<int> random;
		Span sp = Span(10000);
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			const int value = rand();
			random.push_back(value);
		}
		sp.addNumber(random.begin(), random.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
  	{
    	std::cerr << e.what() << "\n";
  	}

	std::cout << "longestSpan with one number:--------\n";
	try
	{
		Span sp = Span(7);
		sp.addNumber(77);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}