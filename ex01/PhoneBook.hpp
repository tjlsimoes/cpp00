#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	add_contact(void);
		void	search(void);

	private:
		Contact		_contacts[8];
		static int	_added_contacts;

		Contact	*get_contacts(void);
		bool	display_contacts(void);
		Contact	*get_contact(int idx);
		Contact	create_contact(void);
		std::string	format_field(std::string str);
		void	idx_prompt(void);
		void	treat_input(std::string *name);
		int		invalid_phone(std::string *name);
};

#endif

// Need to review public and private methods' assignment.