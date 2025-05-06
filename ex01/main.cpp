# include "PhoneBook.hpp"

int	main(void)
{
	std::string	user_input;
	PhoneBook	registry;

	while (true)
	{
		std::cout << "\nNavigate your phonebook with the following commands:" << std::endl;
		std::cout << "ADD: to save a new contact" << std::endl;
		std::cout << "SEARCH: to display a specific contact" << std::endl;
		std::cout << "EXIT: you know... to exit\n" << std::endl;
		std::getline(std::cin, user_input);

		if (std::cin.fail())
			std::cout << "Please enter a valid command" << std::endl;
		else if (user_input.compare("ADD") == 0)
		{
			std::cout << "ADD was the input." << std::endl;
			registry.add_contact();
		}
		else if (user_input.compare("SEARCH") == 0)
		{
			std::cout << "SEARCH was the input." << std::endl;
			registry.search();
		}
		else if (user_input.compare("EXIT") == 0)
			break;
	}

	return (0);
}

// --------------------------------------------------------------------
// --------------   Legitimate use of std::cin   ----------------------
// --------------------------------------------------------------------

// std::getline() was used as std::cin alone would, for example,
//   take "ADD" "IO" as two different inputs.