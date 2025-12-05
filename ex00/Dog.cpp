#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	this->type = src.type;
	std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout <<"Dog copy assignment operator called"<<std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout <<"Dog destructor called"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout <<"Woof!"<<std::endl;
}
