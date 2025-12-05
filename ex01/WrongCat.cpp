#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	this->type = src.type;
	std::cout<<"WrongCat copy constructor called"<<std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout <<"WrongCat copy assignment operator called"<<std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout <<"WrongCat Destructor called"<<std::endl;
}

void WrongCat::makeSound() const
{
	std::cout <<"Meow!"<<std::endl;
}