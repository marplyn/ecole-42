#ifndef FORM_HPP
#define FORM_HPP

# include <string>
# include <ostream>

# include "Bureaucrat.hpp"

class Form
{
	private:
			const std::string name;
			const int gradeToSign;
			const int gradeToExecute;
			bool isFormSigned;
	public:
			Form();
			Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
			Form(const Form& src);
			Form& operator=(const Form& src);
			~Form();

			const std::string& getName() const;
			int getGradeToSign() const;
			int getGradeToExecute() const;
			bool isSigned() const;
			void beSigned(const Bureaucrat& bureaucrat); 
			
			class GradeTooHighException : public std::exception
			{
				public:
						const char* what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
						const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& outputStream, const Form& obj);

#endif