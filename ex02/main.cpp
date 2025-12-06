#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // ------------------------------------------------------------------
    // TEST 1: ABSTRACT CLASS CHECK
    // ------------------------------------------------------------------
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 1: ABSTRACT CLASS CHECK" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    // Animal* test = new Animal();

    // ------------------------------------------------------------------
    // TEST 2: ARRAY OF ANIMALS (Subject Requirement)
    // ------------------------------------------------------------------
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 2: ARRAY OF ANIMALS (Polymorphism & Memory)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    const int arraySize = 4; // Small size for readability
    Animal* animals[arraySize];

    std::cout << "[1] Creating Animals (Half Dogs, Half Cats)..." << std::endl;
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    std::cout << "\n[2] Testing Sounds (Polymorphism)..." << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << ": ";
        animals[i]->makeSound();
    }

    std::cout << "\n[3] Deleting Animals (Checking Virtual Destructors)..." << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }


    // ------------------------------------------------------------------
    // TEST 3: DEEP COPY TEST (Still required from Ex01)
    // ------------------------------------------------------------------
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 3: DEEP COPY TEST" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    std::cout << "[1] Creating original Dog" << std::endl;
    Dog* dog1 = new Dog();
    
    // Ideally, you should set some ideas in dog1's brain here if you implemented setters
    // e.g., dog1->getBrain()->setIdea(0, "I want food");

    std::cout << "\n[2] Creating copy (Deep Copy)" << std::endl;
    Dog* dog2 = new Dog(*dog1);

    std::cout << "\n[3] Deleting original Dog" << std::endl;
    delete dog1;

    std::cout << "\n[4] Checking if copy is still alive (and has its own Brain)" << std::endl;
    // If shallow copy occurred, dog2's brain would be deleted above, causing a crash here or later.
    dog2->makeSound(); 
    
    std::cout << "\n[5] Deleting copy" << std::endl;
    delete dog2;

    return 0;
}