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

void		PhoneBook::PrintContactList ()
{
	std::cout  << std::endl \
		<< std::setw (10) << "INDEX" << '|' \
		<< std::setw (10) << "FIRSTNAME" << '|' \
		<< std::setw (10) << "LASTNAME" << '|' \
		<< std::setw (10) << "NICKNAME" << std::endl;
	for (size_t j = 0; j < ContactNb; j++)
	{
		std::cout << std::setw (10) << j + 1 << '|';
		ContactList[j].PrintFormatContact ();
	}
}

u_int8_t		PhoneBook::GetIndex ()
{
	std::string		input;
	int				i = -1;

	while (i == -1)
	{
		std::cout << std::endl << "index of contact u wanna look at: ";
		if (!std::getline (std::cin, input))
			return (-1);
		i = (input.length () > 1 || !isdigit (input[0])) ? -1 : atoi (input.c_str ());
		if (i <= 0 || i > 8 || i > (int)ContactNb)
			i = -1;
		if (i == -1)
			std::cout << "You wont gonna get any contact with this index" << std::endl;
	}
	return (i);
}

void	PhoneBook::SearchContact ()
{
	PrintContactList ();
	int i = GetIndex ();
	ContactList[i - 1].PrintFullContact ();
}

void	PhoneBook::AddContact ()
{
	static size_t	i = 0;

	ContactList[i % 8].FillContact ();
	if (ContactNb != 8)
		ContactNb++;
	i++;
}

PhoneBook::PhoneBook()
{
	ContactNb = 0;
}