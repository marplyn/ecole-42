#include "Bureaucrat.hpp"

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