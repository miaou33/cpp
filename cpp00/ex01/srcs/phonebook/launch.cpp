/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjeiwjifeoh <fjeiwjifeoh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:26 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/21 15:2 by fjeiwjifeoh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	PrintGreetings (void)
{
	std::cout << std::endl \
		<< "Welcome to ur Phone Book" << std::endl \
		<< "Possible commands :" << std::endl \
		<< "- ADD to create a new contact" << std::endl \
		<< "- SEARCH to print the list of contacts and pick one you wanna look" << std::endl \
		<< "- EXIT to quit (it erase all the contacts)\n" << std::endl;
}

void	PhoneBook::LaunchPhoneBook (PhoneBook p)
{
	std::string		command;

	PrintGreetings ();
	p.ContactNb = 0;
	p.ContactIndex = p.ContactNb;
	while (command != "EXIT")
	{
		if (!std::getline (std::cin, command))
			exit (0);
		if (command == "ADD")
			p.AddContact (&p);
		else if (command == "SEARCH")
			p.SearchContact (p);
		std::cout << std::endl;
	}
}