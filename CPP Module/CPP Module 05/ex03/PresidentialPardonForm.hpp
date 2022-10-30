#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

# include <iostream>

class PresidentialPardonForm: public Form
{
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(const std::string& name, const std::string& target);
			PresidentialPardonForm(const PresidentialPardonForm& src);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
			~PresidentialPardonForm();

			virtual void execute(const Bureaucrat& executor) const;
};

#endif