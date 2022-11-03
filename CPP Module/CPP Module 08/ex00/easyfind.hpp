#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <array>
# include <vector>
# include <list>


template <typename T>
typename T::iterator easyfind(T &container, const int toFind)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), toFind);
	if (iter != container.end())
		std::cout << toFind << " is in this container\n";
	else
		throw std::exception();
	return (iter);
}

#endif