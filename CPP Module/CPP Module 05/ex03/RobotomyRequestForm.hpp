#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm: public Form
{
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const std::string& name, const std::string& target);
			RobotomyRequestForm(const RobotomyRequestForm& src);
			RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
			~RobotomyRequestForm();

			virtual void execute(const Bureaucrat& executor) const;
};

#endif