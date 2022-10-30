#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name,
	const std::string& target) : Form(name, 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& src) : Form(src)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	Form::operator=(src);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkToExecute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";	
}