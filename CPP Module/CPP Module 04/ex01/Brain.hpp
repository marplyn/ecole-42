#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
			Brain();
			Brain(const Brain& other);
			~Brain();
			Brain& operator=(const Brain& other);
			static const size_t IDEAS = 100;
			std::string ideas[IDEAS];
};

#endif