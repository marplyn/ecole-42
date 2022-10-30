#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("NoName", 72, 45, "NoName")
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name,
	const std::string& target) : Form(name, 72, 45, target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& src) : Form(src)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	Form::operator=(src);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkToExecute(executor);
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed\n";
}