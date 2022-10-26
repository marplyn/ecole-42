#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
			Contact	contact[8];
			int		length;
			int		last;
			void	printContact(int i);
			void	printPhoneBook();
	public:
			PhoneBook();
			void	searchContact();
			void	addContact();
};

#endif 