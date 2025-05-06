# include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor was called." << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Destructor was called." << std::endl;
	return ;
}

std::string	Contact::get_first_name(void) const
{
	return this->_first_name;
}

void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
	return ;
}

std::string	Contact::get_last_name(void) const
{
	return this->_last_name;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
	return ;
}

std::string	Contact::get_nickname(void) const
{
	return this->_nickname;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
	return ;
}

std::string	Contact::get_phone(void) const
{
	return this->_phone;
}

void	Contact::set_phone(std::string str)
{
	this->_phone = str;
	return ;
}

std::string	Contact::get_secret(void) const
{
	return this->_secret;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
	return ;
}
