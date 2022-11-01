#ifndef CONVERTION_HPP
# define CONVERTION_HPP

# include <iostream>
# include <cmath>
# include <cstring>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <cctype>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

bool isChar(const std::string& arg);
bool isInt(const std::string& arg);
bool isFloat(const std::string& arg);
bool isDouble(const std::string& arg);
Type whatType(const std::string& arg);

void printChar(const std::string& arg);
void printInt(const std::string& arg);
int printPseudo(const std::string& arg);
void printFloat(const std::string& arg);
void printDouble(const std::string& arg);

#endif