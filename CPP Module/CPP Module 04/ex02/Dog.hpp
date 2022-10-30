#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
			Brain *brain;
	public:
			Dog();
			~Dog();
			Dog(const Dog &src);
			Dog& operator=(const Dog &src);
			void makeSound() const;
			Brain* getBrain() const;
};

#endif