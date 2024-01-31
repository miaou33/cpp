#include <iostream>
#include <string>

int	main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (size_t i = 1; av[i]; i++)
	{
		std::string	str (av[i]);
		for (int j = str.length (); j >= 0; j--)
			str[j] = toupper (str[j]);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
