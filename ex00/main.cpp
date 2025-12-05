#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 1: SUBJECT TESTS (Polymorphism check)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "\n[Type Check]" << std::endl;
        std::cout << "j is a: " << j->getType() << " " << std::endl;
        std::cout << "i is a: " << i->getType() << " " << std::endl;

        std::cout << "\n[Sound Check]" << std::endl;
        std::cout << "Cat (i) says: "; i->makeSound(); // Expect: Meow
        std::cout << "Dog (j) says: "; j->makeSound(); // Expect: Woof
        std::cout << "Meta says:    "; meta->makeSound();

        std::cout << "\n[Destructors Check - Watch for 'Dog' then 'Animal']" << std::endl;
        delete j;
        delete i;
        delete meta;
    }

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 2: WRONG ANIMAL (No virtual keyword)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "\n[Sound Check - Expecting WRONG output]" << std::endl;
        // Since makeSound() is NOT virtual in WrongAnimal, this will assume
        // it's just a generic WrongAnimal, even though it's actually a Cat.
        std::cout << "WrongCat says: ";
        wrongCat->makeSound(); // Expect: WrongAnimal sound (NOT Meow)

        std::cout << "WrongMeta says: ";
        wrongMeta->makeSound();

        std::cout << "\n[Cleanup]" << std::endl;
        delete wrongCat;
        delete wrongMeta;
    }

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 3: CANONICAL FORM (Copy & Assignment)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    {
        std::cout << "[1] Creating original Dog" << std::endl;
        Dog originalDog;
        
        std::cout << "\n[2] Testing Copy Constructor" << std::endl;
        Dog copyDog(originalDog);
        std::cout << "Original Type: " << originalDog.getType() << std::endl;
        std::cout << "Copy Type:     " << copyDog.getType() << std::endl;

        std::cout << "\n[3] Testing Assignment Operator" << std::endl;
        Dog assignedDog;
        assignedDog = originalDog; // This uses your fixed operator=
        std::cout << "Assigned Type: " << assignedDog.getType() << std::endl;
        
        std::cout << "\n[4] Sound Check for Copies" << std::endl;
        copyDog.makeSound();
        assignedDog.makeSound();
    } // Destructors for stack objects called here
return 0;
}