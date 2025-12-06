#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    
    const int arraySize = 10;
    Animal* animals[arraySize];

    std::cout << "--- CREATING ANIMALS ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    std::cout << "\n--- DELETING ANIMALS ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    return 0;
}