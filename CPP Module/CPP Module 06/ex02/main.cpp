#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	Base	*generate;

	switch(std::rand() % 3)
	{
		case 0:
			generate = new A; 
			break ;
		case 1:
			generate = new B;
			break ;
		case 2: 
			generate = new C;
			break;
	}
	return (generate);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "Pointer to B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "Pointer to C\n";
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
	} 
	catch (std::bad_cast & e) 
	{
		try 
		{
			(void)dynamic_cast<B&>(p);
		} 
		catch (std::bad_cast& e) 
		{
			try 
			{
				(void)dynamic_cast<C&>(p);
			} 
			catch (std::bad_cast& e) 
			{	
				std::cout << "Unknown reference\n";	
				return;
			}
			std::cout << "Reference to C\n"; 
			return;	
		}
		std::cout << "Reference to B\n"; 
		return;	
	}		
	std::cout << "Reference to A\n"; 
}

int main (void)
{
	Base *p;

	p = generate();
	identify(p);
	identify(*p);

	delete p;
	return (0);
}