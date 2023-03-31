/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayCasts.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/22 21:38:32 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::PrintInfosTitles (size_t index)
{
	static std::string	ContactTitles[5] = {"First Name", \
											"Last Name", \
											"Nickname", \
											"Number", \
											"Secret"};

	if (index > 4)
		return ;
	std::cout << ContactTitles[index] << ": ";
}

void	Contact::PrintFullContact ()
{
 	for (size_t i = 0; i < 5; i++)
	{
		PrintInfosTitles(i);
		std::cout << Infos[i] << std::endl;
	}
}

static void	PrintString (std::string s)
{
	if (s.length () > 10)
	{
		s.resize(9);
		s.append(".");
	}
	std::cout << std::setw (10);
	std::cout << s;
}

void	Contact::PrintFormatContact (void)
{
	for (size_t i = 0; i < number; i++)
	{
		PrintString (Infos[i]);
		if (i != nickname)
			std::cout << '|';
	}
	std::cout << std::endl;
}

void	Contact::FillContact ()
{
	bool	blank;

	for (size_t j = 0; j < 5; j++)
	{
		blank = 1;
		while (blank)
		{
			PrintInfosTitles (j);
			if (!std::getline (std::cin, Infos[j]))
				return ;
			if (Infos[j].empty ())
				std::cout << "Error: Empty field" << std::endl;
			else
				blank = 0;
		}
	}
}
