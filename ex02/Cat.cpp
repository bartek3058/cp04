#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called"<<std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &src)
{
	this->brain = new Brain(*src.brain);
	std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	std::cout <<"Cat copy assignment operator called"<<std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout <<"Cat Destructor called"<<std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout <<"Meow!"<<std::endl;
}