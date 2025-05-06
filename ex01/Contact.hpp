#ifndef CONTACT_H
# define CONTACT_H
# include <string>
# include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string		get_first_name(void) const;
		void			set_first_name(std::string str);

		std::string		get_last_name(void) const;
		void			set_last_name(std::string str);

		
		std::string		get_nickname(void) const;
		void			set_nickname(std::string str);

		std::string		get_phone(void) const;
		void			set_phone(std::string str);

		std::string		get_secret(void) const;
		void			set_secret(std::string str);
	
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
};

#endif