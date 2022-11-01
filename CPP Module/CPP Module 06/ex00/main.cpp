#include "convertion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments!\n";
		return (1);
	}
	std::string arg(argv[1]);
	Type type = whatType(arg);
	switch (type)
	{
		case CHAR:
			printChar(arg);
			break ;
		case INT:
			printInt(arg);
			break ;
		case FLOAT:
			printFloat(arg);
			break ;
		case DOUBLE:
			printDouble(arg);
			break ;
		default:
			printDouble("nan");
	}
	return (0);
}