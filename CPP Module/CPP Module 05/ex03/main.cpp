#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	Form *ppf = NULL;
	Form *rrf = NULL;
	Form *scf = NULL;

	try
	{
		std::cout << "InternCreatingForm:----------------------\n";
		Intern someRandomIntern;
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");	
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");	
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");

		std::cout << "ShrubberyCreationForm:----------------------\n";
		{
			Bureaucrat bureaucrat1("bureaucrat1", 146);
			Bureaucrat bureaucrat3("bureaucrat3", 135);
			Bureaucrat bureaucrat2("bureaucrat2", 100);

			bureaucrat1.signForm(*scf);
			bureaucrat2.executeForm(*scf);
			bureaucrat3.signForm(*scf);
			bureaucrat2.executeForm(*scf);
		}

		std::cout << "RobotomyRequestForm:----------------------\n";
		{
			Bureaucrat bureaucrat1("bureaucrat1", 146);
			Bureaucrat bureaucrat3("bureaucrat3", 70);
			Bureaucrat bureaucrat2("bureaucrat2", 40);

			bureaucrat1.signForm(*rrf);
			bureaucrat2.executeForm(*rrf);
			bureaucrat3.signForm(*rrf);
			bureaucrat2.executeForm(*rrf);
		}

		std::cout << "PresidentialPardonForm:----------------------\n";
		{
			Bureaucrat bureaucrat1("bureaucrat1", 30);
			Bureaucrat bureaucrat3("bureaucrat3", 15);
			Bureaucrat bureaucrat2("bureaucrat2", 3);

			bureaucrat1.signForm(*ppf);
			bureaucrat2.executeForm(*ppf);
			bureaucrat3.signForm(*ppf);
			bureaucrat2.executeForm(*ppf);
		}
		
		std::cout << "InternCreatingUnexistingFrom:----------------------\n";
		Form *uf = someRandomIntern.makeForm("unknown form", "Bender");	
		delete(uf);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";	
	}

	delete(ppf);
	delete(rrf);
	delete(scf);

	return (0);
}