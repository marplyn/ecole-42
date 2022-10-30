#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] default contructor is called\n";
}

Brain::Brain(const Brain& src)
{
	std::cout << "[Brain] copy constructor is called\n";
	*this = src;
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor is called\n";
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] copy assignment operator is called\n";
	if (&other != this) {
		for (size_t i = 0; i < IDEAS; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}