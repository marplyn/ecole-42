#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Form;

class Bureaucrat
{
	private:
			const std::string name;
			int grade;
	public:
			static const int MAX_GRADE = 1;
			static const int MIN_GRADE = 150;
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& src);
			Bureaucrat& operator=(const Bureaucrat& src);	
			~Bureaucrat();

			const std::string& getName() const;
			int getGrade() const;
			void incrementGrade();
			void decrementGrade();
			void signForm(Form& form) const;			
						
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

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& obj);

#endif