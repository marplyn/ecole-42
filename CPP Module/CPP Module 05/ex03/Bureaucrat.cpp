#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("NoName"), grade(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (&src != this) {
		const_cast<std::string&>(name) = src.name;
		grade = src.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade == MAX_GRADE)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade()
{
	if (grade == MIN_GRADE)
		throw GradeTooLowException();
	++grade;
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldn’t sign " << form.getName()
				  << " because " << " bureaucrat's " << e.what() << "\n";
	}	
}

void Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "\n";	
	}
	catch (std::exception & e)
	{
		std::cout << name << " cannot execute " << form.getName()
				  << " because " << e.what() << "\n";
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: grade is too low!");
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& obj)
{
	outputStream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (outputStream);
}