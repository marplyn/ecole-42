#include "MutantStack.hpp"

int main(void)
{
	std::cout << "Mutated Stack:-------\n";
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Mutant stack top: " << mstack.top() << std::endl;
		std::cout << "Mutant stack size: " << mstack.size() << std::endl;
		
		mstack.pop();
		std::cout << "Mutant stack size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5); 
		mstack.push(737);

		MutantStack<int>::iterator it = mstack.begin(); 
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Iterating stack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it; 
		}
	}

	std::cout << "List:----------------\n";
	{
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << "List top: " << mlist.back() << std::endl;
		std::cout << "List size: " << mlist.size() << std::endl;
		
		mlist.pop_back();
		std::cout << "List size: " << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5); 
		mlist.push_back(737);

		std::list<int>::iterator it = mlist.begin(); 
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		std::cout << "Iterating list:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it; 
		}
	}

	return (0);
}
