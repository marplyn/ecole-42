#include "convertion.hpp"

bool isChar(const std::string& arg)
{
	return (arg.length() == 1 && !std::isdigit(arg[0]));
}

bool isInt(const std::string& arg)
{
	char* 	endptr;
	long int input;

	input = std::strtol(arg.c_str(), &endptr, 10);

	return  (!endptr[0] && input >= std::numeric_limits<int>::min()
			&& input <= std::numeric_limits<int>::max());
}

bool isFloat(const std::string& arg)
{
	char* endptr;
	double input;

	input = std::strtod(arg.c_str(), &endptr);

	return (arg == "nanf" || arg == "-inff" || arg == "+inff" || 
			(endptr[0] && std::string(endptr) == "f" && std::abs(input) <= std::numeric_limits<float>::max()));
}

bool isDouble(const std::string& arg)
{
	char* endptr;

	std::strtod(arg.c_str(), &endptr);
	errno = 0;

	return (arg == "nan" || arg == "-inf" || arg == "+inf" ||
			(!endptr[0] && errno != ERANGE));
}

Type whatType(const std::string& arg)
{
	if (isChar(arg))
		return (CHAR);
	else if (isInt(arg))
		return(INT);	
	else if (isFloat(arg))
		return (FLOAT);
	else if (isDouble(arg))
		return (DOUBLE);	
	else
		return (OTHER);
}