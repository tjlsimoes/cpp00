#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "Contact.hpp"
# include <iomanip>

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
		void	user_input_error(void);
		Contact	create_contact(void);
		std::string	format_field(std::string str);
		void	idx_prompt(void);
};

#endif

// Need to review public and private methods' assignment.