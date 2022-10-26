#include "PhoneBook.hpp"
#include <cstdio>


int	main(void)
{
	std::string	str;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Enter command: ";
		std::cin >> std::ws;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << '\n';
			std::cin.clear();
			std::clearerr(stdin);
		}
		else if (str == "ADD")
			phonebook.addContact();
		else if (str == "SEARCH")
			phonebook.searchContact();
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Command not found!\n";
	}
	return (0);
}
