#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void check_leak(){
	system("leaks ex01");
}

#define SIZE_GROUP 6
int main(){
	atexit(check_leak);
	Animal* animalGroup[SIZE_GROUP];
    
    std::cout << "------------------CONSTRUCTOR-------------------" << std::endl ;
    for (int i = 0; i < SIZE_GROUP; i++)
    {
        if(i < SIZE_GROUP / 2)
            animalGroup[i] = new Cat();
        else
            animalGroup[i] = new Dog();
    }
    
    std::cout << "------------------DESTRUCTOR-------------------" << std::endl ;
    for (int i = 0; i < SIZE_GROUP; i++)
    {
        delete animalGroup[i];
    }
    
    std::cout << "--------------------COPY---------------------" << std::endl ;
    const Cat cat;
    const Dog dog;
    Cat sirius(cat);
    Dog jake(dog);

    std::cout << "--------------------IDEAS----------------------" << std::endl ;
    std::cout << "--------->DEFAULT:" << std::endl ;
    std::cout << *sirius.getBrain()->getIdeas() << std::endl;
    std::cout << "--------->SIRIUS:" << std::endl ;
    sirius.getBrain()->setIdeas("I love tuna!");
    std::cout << "Sirius`s idea: " << *sirius.getBrain()->getIdeas() << std::endl;

    const std::string *ideas;
    jake.getBrain()->setIdeas("Let`s go to the park!");
    std::cout << "--------->JAKE:" << std::endl ;
    ideas = jake.getBrain()->getIdeas();
    for(int i = 0; i < 3; i++)
        std::cout << "Jake`s idea: " << ideas[i] << std::endl;

    std::cout << "----------------DEEPCOPIES--BRAIN------------" << std::endl ;
    Cat originalCat;
    Cat deepcopyCat;
    
    deepcopyCat = originalCat;

    originalCat.getBrain()->setIdeas("Let`s go to the park!");
    std::cout << "--------->ORIGINAL:" << std::endl ;
    ideas = originalCat.getBrain()->getIdeas();
    for(int i = 0; i < 3; i++)
        std::cout << "original`s idea: " << ideas[i] << "\t address: " << &ideas[i] << std::endl;
    
    ideas = deepcopyCat.getBrain()->getIdeas();
    for(int i = 0; i < 3; i++)
        std::cout << "deep`s idea: " << ideas[i] << "\t\t address: " << &ideas[i] << std::endl;

    std::cout << "----------------DEEPCOPIES------------------" << std::endl ;
    Animal* originalDog = new Dog();
    Animal* deepCopyDog = new Dog(*(Dog*)(originalDog));
	std::cout << "---------------------------------------" << std::endl ;
    std::cout << "original addresss: " << std:: endl;
    originalDog->printAddress();
    std::cout << "deepcopy addresss: " << std:: endl;
    deepCopyDog->printAddress();

    std::cout << "---------------------------------------" << std::endl ;

    delete originalDog;
    delete deepCopyDog;

	return 0;
}