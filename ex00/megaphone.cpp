# include <cctype>
# include <iostream>

bool	str_toupper(char *str, bool end)
{
	int				i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (std::isalpha(str[i]) && std::islower(str[i]))
			std::cout << static_cast<unsigned char>(std::toupper(str[i]));
		else
			std::cout << static_cast<unsigned char>(str[i]);
		i++;
	}
	if (end)
		std::cout << std::endl;
	return (true);
}

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
