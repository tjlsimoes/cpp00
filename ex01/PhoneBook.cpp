#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor was called." << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor was called." << std::endl;
	return ;
}

Contact *PhoneBook::get_contacts(void)
{
	return (this->_contacts);
}

void	PhoneBook::user_input_error(void)
{
	std::cout << "Invalid user input." << std::endl;
	std::cout << "Aborting contact creation." << std::endl;
}

Contact	PhoneBook::create_contact(void)
{
	Contact		add;
	std::string	name;

	std::cout << "\nPlease enter the first name: " << std::endl;
	std::getline(std::cin, name);
	if (name.empty())
		return (PhoneBook::user_input_error(), add);
	add.set_first_name(name);
	name.erase();

	std::cout << "Please enter the last name: " << std::endl;
	std::getline(std::cin, name);
	if (name.empty())
		return (PhoneBook::user_input_error(), add);
	add.set_last_name(name);
	name.erase();
	
	std::cout << "Please enter the phone number: " << std::endl;
	std::getline(std::cin, name);
	if (name.empty())
		return (PhoneBook::user_input_error(), add);
	add.set_phone(name);
	name.erase();

	std::cout << "Please enter the secret: " << std::endl;
	std::getline(std::cin, name);
	if (name.empty())
		return (PhoneBook::user_input_error(), add);
	add.set_secret(name);
	name.erase();

	std::cout << '\n';
	return (add);
}

// Trim tabs somehow.

void	PhoneBook::add_contact(void)
{
	Contact add;

	add = PhoneBook::create_contact();
	// Need to check for user input error?
	PhoneBook::_added_contacts += 1;
	if (PhoneBook::_added_contacts == 8)
		PhoneBook::_added_contacts = 0;
	PhoneBook::get_contacts()[PhoneBook::_added_contacts] = add;
	return ;
}

std::string	PhoneBook::format_field(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::search(void)
{
	if (display_contacts())
		idx_prompt();
	return ;
}

bool	PhoneBook::display_contacts(void)
{
	int			i;
	Contact		*contacts;

	if (PhoneBook::_added_contacts < 0)
		return (false);
	i = 0;
	contacts = get_contacts();
	while (i <= PhoneBook::_added_contacts)
	{
		std::cout << std::right
			<< std::setw(10) << i << "|"
			<< std::setw(10) << format_field(contacts[i].get_first_name()) << "|"
			<< std::setw(10) << format_field(contacts[i].get_last_name()) << "|"
			<< std::setw(10) << format_field(contacts[i].get_phone()) << "|"
			<< std::setw(10) << format_field(contacts[i].get_secret()) << "\n";
		i++;
	}
	std::cout << std::left;
	std::cout << std::endl;
	return (true);
}

void	PhoneBook::idx_prompt(void)
{
	std::string		i;
	Contact			*contact;
	int				i_nbr;

	while (true)
	{
		std::cout << "Please specify contact index: [e.g. 0]\n";
		// std::cin >> i;
		std::getline(std::cin, i);
		if (std::cin.eof())
			return ;
		i_nbr = std::atoi(i.c_str()); 
		if (i_nbr < 0 || i_nbr > _added_contacts)
			std::cout << "Invalid index. Please try again.\n";
		else
			break;
	}
	contact = get_contact(i_nbr);
	std::cout
		<< "\nFirst name: " << (*contact).get_first_name() << "\n"
		<< "Last name: " << (*contact).get_last_name() << "\n"
		<< "Phone number: " << (*contact).get_phone() << "\n"
		<< "Secret: " << (*contact).get_secret() << "\n\n";
}

Contact *PhoneBook::get_contact(int idx)
{
	if (idx >= 0 && idx <= PhoneBook::_added_contacts)
		return (&(this->_contacts[idx]));
	else
		return (NULL);
}

int	PhoneBook::_added_contacts = -1;


// --------------------------------------------------------------------
// --------------   std::endl? Not '\n\ instead?   --------------------
// --------------------------------------------------------------------