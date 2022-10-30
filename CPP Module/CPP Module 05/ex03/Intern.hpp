#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

#include "Form.hpp"


class Intern
{
	private:
			static const int FORM_COUNT = 3;
			static const std::string PRES_PARDON;
			static const std::string ROB_REQ;
			static const std::string SHRUB_CREAT;

			Form* makePresidentialPardonForm(const std::string& target) const;
			Form* makeRobotomyRequestForm(const std::string& target) const;
			Form* makeShrubberyCreationForm(const std::string& target) const;

			typedef Form* (Intern::*FormMaker)(const std::string& target) const;

			struct FormPattern
			{
				std::string name;
				FormMaker makeForm;
			};

			static const FormPattern formPatterns[];	
	public:
			Intern();
			Intern(const Intern& src);
			Intern& operator=(const Intern& src);
			~Intern();

			class FormDoesNotExistException : public std::exception
			{
				public:
						const char* what() const throw();
			};

			Form* makeForm(const std::string& name, const std::string& target) const;	
	};

#endif