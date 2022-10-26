#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip> 

class Contact
{
	private:
			std::string	firstname;
			std::string	lastname;
			std::string	nickname;
			std::string	phonenumber;
			std::string	darkestsecret;
			void		doFormating(std::string str);
	public:
			void		fillContact();
			void		printFullContact();
			void		printFormatedContact();
};

#endif