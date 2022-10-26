#include <iostream>
#include <cctype>

void	printEnlargedStr(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			char c = std::toupper(argv[i][j]);
			std::cout << c;
		}
		if (i != argc - 1)
			std::cout << " ";
	}
	std::cout << "\n";
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		printEnlargedStr(argc, argv);
	return (0);
}
