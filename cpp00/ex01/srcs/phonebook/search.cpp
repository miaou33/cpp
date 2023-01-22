/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjeiwjifeoh <fjeiwjifeoh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:33:39 by fjeiwjifeoh       #+#    #+#             */
/*   Updated: 2023/01/21 19:0 by fjeiwjifeoh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	PrintFormatContact (std::string s)
{
	if (s.length () > 10)
	{
		s.resize(9);
		s.append(".");
	}
	std::cout << std::setw (10);
	std::cout << s;
}

void	PhoneBook::PrintContactElem (Contact c)
{
	for (size_t i = 0; i < number; i++)
	{
		PrintFormatContact(c.Infos[i]);
		if (i != nickname)
			std::cout << '|';
	}
	std::cout << std::endl;
}

static void		PrintContactList (PhoneBook p)
{
	std::cout  << std::endl \
		<< std::setw (10) << "INDEX" << '|' \
		<< std::setw (10) << "FIRSTNAME" << '|' \
		<< std::setw (10) << "LASTNAME" << '|' \
		<< std::setw (10) << "NICKNAME" << std::endl;
	for (size_t j = 0; j < p.ContactNb; j++)
	{
		std::cout << std::setw (10) << j + 1 << '|';
		p.PrintContactElem (p.ContactList[j]);
	}
}

static u_int8_t		GetIndex (PhoneBook p)
{
	std::string		input;
	int				index = -1;

	while (index == -1)
	{
		std::cout << std::endl << "Index of contact u wanna look at: ";
		if (!std::getline (std::cin, input))
			return (-1);
		if (input.length () > 1 || !isdigit (input[0]))
			index = -1;
		else
		{
			index = atoi (input.c_str ());
			if (index <= 0 || index > 8 || index > (int)p.ContactNb)
				index = -1;
		}
		if (index == -1)
			std::cout << "You wont gonna get any contact with this index" << std::endl;
	}
	return (index);
}

static void		PrintFullContact (Contact c)
{
	c.PrintOneContact (c);
}

void	PhoneBook::SearchContact (PhoneBook p)
{
	PrintContactList (p);
	int i = GetIndex (p);
	PrintFullContact (p.ContactList[i - 1]);
}