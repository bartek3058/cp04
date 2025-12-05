#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	this->type = src.type;
	std::cout << "Animal copy constructed called"<<std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout <<"Animal copy assignment operator called"<<std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout <<"Animal destructor called"<<std::endl;
}

void Animal::makeSound() const
{
	std::cout <<"Default Animal sound!"<<std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}