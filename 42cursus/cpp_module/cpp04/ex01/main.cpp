#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void check_leak(){
	system("leaks ex01");
}

int main(){
	{
		atexit(check_leak);
		std::cout << "\ncorrect class\n";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	return 0;
}