#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &src)
{
	this->brain = new Brain(*src.brain);
	std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	std::cout <<"Dog copy assignment operator called"<<std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout <<"Dog destructor called"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout <<"Woof!"<<std::endl;
}
