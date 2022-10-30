#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("NoName", 145, 137, "NoName")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, 
	const std::string& target) : Form(name, 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& src) : Form(src)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	Form::operator=(src);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkToExecute(executor);
	std::string fileName = target + "_shrubbery";
	std::ofstream outFile;
	outFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	outFile.open(fileName.c_str(), std::ios_base::out | std::ios_base::trunc);
	outFile << \
		"	               _-_			  		\n"
		"              //~~   ~~\\			    \n"
		"           //~~         ~~\\		    \n"
		"           {               }		    \n"
		"           \\  _-     -_  //		    \n"
		"              ~  \\ //  ~	            \n"
		"           _- -   | | _- _		        \n"
		"             _ -  | |   -_             \n"
		"                  | |         		    \n"
		"                 // \\                 \n";
	outFile.close();
}
