#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook		p;
	std::string		command;

	std::cout << std::endl \
		<< "Welcome to ur Phone Book" << std::endl \
		<< "Possible commands :" << std::endl \
		<< "- ADD to create a new contact" << std::endl \
		<< "- SEARCH to displayCasts the list of contacts and pick one you wanna look" << std::endl \
		<< "- EXIT to quit (it erase all the contacts)\n" << std::endl;
	while (command != "EXIT")
	{
		if (!std::getline (std::cin, command))
			exit (0);
		if (command == "ADD")
			p.AddContact ();
		else if (command == "SEARCH")
			p.SearchContact ();
		std::cout << std::endl;
	}
	return (0);
}