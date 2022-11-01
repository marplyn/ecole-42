#include "convertion.hpp"

void printChar(const std::string& arg)
{
	char c = arg[0];

	std::cout << "char: ";
	std::isprint(c) ? std::cout << c << "\n" : std::cout << "Non displayable\n";

	int	i = static_cast<int>(c);
	std::cout << "int: " << i << "\n";

	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << "\n";

	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << "\n";
}

void printInt(const std::string& arg)
{
	int i = static_cast<int>(std::strtol(arg.c_str(), NULL, 10));

	char c = static_cast<char>(i);
	std::cout << "char: ";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << "\n";

	std::cout << "int: " << i << "\n";

	float f = static_cast<float>(i);
	std::cout << "float: " << f << ".0f" << "\n";
	
	double d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" << "\n";
}

int printPseudo(const std::string& arg)
{
	if (arg == "-inf" || arg == "-inff")
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: -inff\n"
				  << "double: -inf\n";
		return (1);
	}
	if (arg == "+inf" || arg == "+inff" || arg == "inf" || arg == "inff")
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: +inff\n"
				  << "double: +inf\n";
		return (1);
	}
	if (arg == "nan" || arg == "nanf")
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: nanf\n"
				  << "double: nan\n";
		return (1);
	}
	return (0);
}

void printFloat(const std::string& arg)
{
	if (printPseudo(arg))
		return;

	double d = std::strtod(arg.c_str(), NULL);

	char c = static_cast<char>(d);
	std::cout << "char: ";
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << "\n";

	int i = static_cast<int>(d);
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";

	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (std::floor(f) == f)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << "\n";

	std::cout << "double: " << d;
	if (std::floor(d) == d)
		std::cout << ".0"; 
	std::cout << "\n";
}

void printDouble(const std::string& arg)
{
	if (printPseudo(arg))
		return;

	double d = std::strtod(arg.c_str(), NULL);
		
	char c = static_cast<char>(d);
	std::cout << "char: ";
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << "\n";

	int i = static_cast<int>(d);
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";

	float f = static_cast<float>(d);
	std::cout << "float: "; 
	if (std::abs(d) > std::numeric_limits<float>::max())
		std::cout << "impossible\n";
	else
	{
		std::cout << f;
		if (std::floor(f) == f)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << "\n";
	}

	std::cout << "double: " << d;
	if (std::floor(d) == d)
		std::cout << ".0"; 
	std::cout << "\n";
}
