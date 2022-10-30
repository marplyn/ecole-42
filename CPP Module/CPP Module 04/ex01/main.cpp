#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	std::cout << "Subject tests:----------------------\n";
	const size_t NB_ANIMALS = 4;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "Creation:----------------------\n";

	Animal* animals[NB_ANIMALS];

	size_t k = 0;
	for (; k < NB_ANIMALS / 2; ++k)
		animals[k] = new Cat();
	for (; k < NB_ANIMALS; ++k)
		animals[k] = new Dog();

	std::cout << "Deletion:----------------------\n";

	for (k = 0; k < NB_ANIMALS; ++k)
		delete animals[k];

	std::cout << "Playing with brain:----------------------\n";

	Cat catA;
	Cat catB;

	catA.getBrain()->ideas[42] = "i have an idea!!!";
	catB.getBrain()->ideas[42] = "i have no idea(((";

	std::cout << "catA idea42: " << catA.getBrain()->ideas[42] << "\n";
	std::cout << "catB idea42: " << catB.getBrain()->ideas[42] << "\n";

	std::cout << catA.getBrain() << "\n";
	std::cout << catB.getBrain() << "\n";

	catB = catA;

	std::cout << catA.getBrain() << "\n";
	std::cout << catB.getBrain() << "\n";

	std::cout << "catA idea42: " << catA.getBrain()->ideas[42] << "\n";
	std::cout << "catB idea42: " << catB.getBrain()->ideas[42] << "\n";

	return (0);
}