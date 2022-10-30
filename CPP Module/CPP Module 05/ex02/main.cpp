#include <iostream>
#include <cstdio>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "ShrubberyCreationForm:----------------------\n";
	{
		ShrubberyCreationForm shrubberyCreationForm("ShrubberyForm", "Shrubbery");
		Bureaucrat bureaucrat1("Bureaucrat1", 146);
		Bureaucrat bureaucrat2("Bureaucrat2", 135);
		Bureaucrat bureaucrat3("Bureaucrat3", 100);

		bureaucrat1.signForm(shrubberyCreationForm);
		bureaucrat3.executeForm(shrubberyCreationForm);
		bureaucrat2.signForm(shrubberyCreationForm);
		bureaucrat3.executeForm(shrubberyCreationForm);
	}
	std::cout << "RobotomyRequestForm:----------------------\n";
	{
		RobotomyRequestForm robotomyRequestForm("RobotomyForm", "Robotomy");
		Bureaucrat bureaucrat1("Bureaucrat1", 146);
		Bureaucrat bureaucrat2("Bureaucrat2", 70);
		Bureaucrat bureaucrat3("Bureaucrat3", 40);

		bureaucrat1.signForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat2.signForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
	}
	std::cout << "PresidentialPardonForm:----------------------\n";
	{
		PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm", "President");
		Bureaucrat bureaucrat1("Bureaucrat1", 30);
		Bureaucrat bureaucrat2("Bureaucrat2", 15);
		Bureaucrat bureaucrat3("Bureaucrat3", 3);

		bureaucrat1.signForm(presidentialPardonForm);
		bureaucrat3.executeForm(presidentialPardonForm);
		bureaucrat2.signForm(presidentialPardonForm);
		bureaucrat3.executeForm(presidentialPardonForm);
	}
	return (0);
}