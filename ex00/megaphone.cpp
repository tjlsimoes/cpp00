# include <cctype>
# include <iostream>

bool	str_toupper(char *str, bool end)
{
	int				i;
	unsigned char	ch;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		ch = static_cast<unsigned char>(str[i]);
		if (std::isalpha(ch) && std::islower(ch))
			std::cout << static_cast<unsigned char>(std::toupper(ch));
		else
			std::cout << ch;
		i++;
	}
	if (end)
		std::cout << std::endl;
	return (true);
}
// --------------------------------------------------------------------
// --------------   Legitimate use of <cctype>?   ---------------------
// --------------------------------------------------------------------

// Verification that ch is alpha and lower was made as std::toupper
//   as std::toupper converts the given character to uppercase
//   according to the character conversion rules defined by the
//   currently installed C locale.
// Cast into unsigned char to prevent undefined behaviour.
//    If the value of ch is not representable as unsigned
//    char and does not equal EOF, the behavior is undefined.

int	main(int argc, char **argv)
{
	int		i;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (!str_toupper(argv[i], (i == argc - 1) ? true : false))
			return (1);
		i++;
	}
	return (0);
}
