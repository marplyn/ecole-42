#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
			Cat();
			~Cat();
			Cat(const Cat &src);
			Cat& operator=(const Cat &src);
			void makeSound() const;
};

#endif