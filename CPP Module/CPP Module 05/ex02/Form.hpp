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
			void checkGrades() const;
	protected:
			Form(const int gradeToSign, const int gradeToExecute);
			void checkToExecute(const Bureaucrat& executor) const;
			const std::string target;
	public:
			Form();
			Form(const std::string& name, const int gradeToSign,
							const int gradeToExecute, const std::string &target);
			Form(const Form& src);
			Form& operator=(const Form& src);
			virtual ~Form();

			const std::string& getName() const;
			int getGradeToSign() const;
			int getGradeToExecute() const;
			bool isSigned() const;
			void beSigned(const Bureaucrat& bureaucrat); 

			virtual void execute(const Bureaucrat& executor) const = 0;
			
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

			class FormNotSignedException : public std::exception
			{
				public:
						const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& outputStream, const Form& obj);

#endif