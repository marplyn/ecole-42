#include "Form.hpp"

Form::Form() : name("NoName"), gradeToSign(Bureaucrat::MAX_GRADE),
	gradeToExecute(Bureaucrat::MAX_GRADE), isFormSigned(false), target("NoTarget")
{
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute, 
const std::string &target) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), 
		isFormSigned(false), target(target)
{
	if (gradeToSign < Bureaucrat::MAX_GRADE || gradeToExecute < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException(); 
	if (gradeToSign > Bureaucrat::MIN_GRADE || gradeToExecute > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException(); 
}

Form::Form(const int gradeToSign, const int gradeToExecute) :
	gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < Bureaucrat::MAX_GRADE || gradeToExecute < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException(); 
	if (gradeToSign > Bureaucrat::MIN_GRADE || gradeToExecute > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException(); 
}

Form::Form(const Form& src) : name("NoName"), gradeToSign(Bureaucrat::MAX_GRADE),
	gradeToExecute(Bureaucrat::MAX_GRADE)
{
	*this = src;
}

Form& Form::operator=(const Form& src) {
	if (&src != this)
	{
		const_cast<std::string&>(name) = src.name;
		const_cast<int&>(gradeToSign) = src.gradeToSign;
		const_cast<int&>(gradeToExecute) = src.gradeToExecute;
		isFormSigned = src.isFormSigned;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return (name);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

bool Form::isSigned() const
{
	return (isFormSigned);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() >= gradeToSign)
		throw GradeTooLowException();
	isFormSigned = true;	
}

void Form::checkToExecute(const Bureaucrat& executor) const
{
	if (!isFormSigned)
		throw FormNotSignedException();
	if (executor.getGrade() >= gradeToExecute)
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream& operator<<(std::ostream& outputStream, const Form& obj)
{
	outputStream << obj.getName() << ", form signed " << obj.isSigned(); 
	return (outputStream);
}