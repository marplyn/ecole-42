#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <string>
# include <stack>
# include <clocale>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
    MutantStack<T>() {}
    MutantStack<T>(const MutantStack<T> &src) : std::stack<T>(src) {}
    ~MutantStack<T>() {}

    MutantStack<T> &operator=(const MutantStack<T> &src)
	{
        (void) src;
        return *this;
    };

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
	{
        return (std::stack<T>::c.begin());
    };

    iterator end()
	{
        return (std::stack<T>::c.end());
    };

};

#endif