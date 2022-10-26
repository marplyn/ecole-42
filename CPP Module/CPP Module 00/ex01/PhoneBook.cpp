#include "PhoneBook.hpp"

void	PhoneBook::printContact(int i)
{
	std::cout << "         " << i << '|';
	contact[i].printFormatedContact();
}

void	PhoneBook::printPhoneBook()
{
	int	i = -1;
	std::cout << "     index" << "|" << "First Name" << '|' << \
	" Last Name" << '|' << \
	" Nickname " << '|' << '\n';
	while (++i < length)
		printContact(i);
}

PhoneBook::PhoneBook()
{
	this->length = 0;
	this->last = 0;
}

void	PhoneBook::searchContact()
{
	int	i;
	printPhoneBook();
	std::cout << "Enter an index: \n";
	std::cin >> i;
	if (std::cin.fail() || i < 0 || i >= length)
	{
		std::cin.clear();
		std::cout << "Wrong index!\n";
	}
	else
		contact[i].printFullContact();
	std::cin.ignore();
}

void	PhoneBook::addContact()
{
	Contact contact;
	contact.fillContact();
	this->contact[last] = contact;
	last++;
	if (last == 8)
		last = 0;
	if (length < 8)
		length++;
}