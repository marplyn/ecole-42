#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Greig", 42);
		std::cout << bureaucrat << "\n";
		Form form1("form1", 50, 42);
		Form form2("form2", 40, 42);
		Form form3("form3", 60, 42);
		std::cout << form1 << "\n";
		std::cout << form2 << "\n";
		std::cout << form3 << "\n";
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		bureaucrat.signForm(form3);
		std::cout << form1 << "\n";
		std::cout << form2 << "\n";
		std::cout << form3 << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}