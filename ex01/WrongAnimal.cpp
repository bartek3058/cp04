#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	this->type = src.type;
	std::cout << "WrongAnimal copy constructed called"<<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout <<"WrongAnimal copy assignment operator called"<<std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<"WrongAnimal destructor called"<<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout <<"WrongAnimal Default sound!"<<std::endl;
}

std::string WrongAnimal::getType()
{
	return this->type;
}