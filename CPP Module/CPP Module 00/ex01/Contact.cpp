#include "Contact.hpp"

void	Contact::doFormating(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) + '.';
	else
		std::cout << std::setw(10) << str;
	std::cout << '|';
}

void	Contact::fillContact()
{
	std::cout << "Input contact information:\n";

	std::cout << "First Name: ";
	std::cin >> std::ws;
	std::getline(std::cin, firstname);

	std::cout << "Last Name: ";
	std::cin >> std::ws;
	std::getline(std::cin, lastname);

	std::cout << "Nickname: ";
	std::cin >> std::ws;
	std::getline(std::cin, nickname);

	std::cout << "Phone Number: ";
	std::cin >> std::ws;
	std::getline(std::cin, phonenumber);

	std::cout << "Darkest Secret: ";
	std::cin >> std::ws;
	std::getline(std::cin, darkestsecret);

	if (std::cin.eof())
	{
		std::cout << "\n^D Error\n";
		// exit (1);
	}
	else
		std::cout << "Contact has been added!\n";
}

void	Contact::printFullContact()
{
	std::cout << "First Name: " + firstname + '\n' +
	"Last Name: " + lastname + '\n' +
	"Nickname: " + nickname + '\n' +
	"Phone Number: " + phonenumber + '\n' +
	"Darkest Secret: " + darkestsecret + '\n';
}

void Contact::printFormatedContact()
{
	doFormating(firstname);
	doFormating(lastname);
	doFormating(nickname);
	std::cout << '\n';
}
