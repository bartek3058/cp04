#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat &src)
{
	this->type = src.type;
	std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout <<"Cat copy assignment operator called"<<std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout <<"Cat Destructor called"<<std::endl;
}

void Cat::makeSound() const
{
	std::cout <<"Meow!"<<std::endl;
}