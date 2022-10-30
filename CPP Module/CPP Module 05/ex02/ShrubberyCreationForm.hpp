#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(const std::string& name, const std::string& target);
			ShrubberyCreationForm(const ShrubberyCreationForm& src);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
			~ShrubberyCreationForm();

			virtual void execute(const Bureaucrat& executor) const;
	};

#endif