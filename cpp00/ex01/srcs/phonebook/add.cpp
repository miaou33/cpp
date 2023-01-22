/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:57:39 by fjeiwjifeoh       #+#    #+#             */
/*   Updated: 2023/01/22 16:22:07 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static Contact	FillContact ()
{
	Contact	c;
	bool	blank;

	for (size_t j = 0; j < 5; j++)
	{
		blank = 1;
		while (blank)
		{
			c.PrintInfosTitles (j);
			if (!std::getline (std::cin, c.Infos[j]))
				exit (0);
			if (c.Infos[j].empty ())
				std::cout << "Error: Empty field" << std::endl;
			else
				blank = 0;
		}
	}
	return (c);
}

void	PhoneBook::AddContact (PhoneBook *p)
{
	if (p->ContactIndex == 8)
	{
		std::cout << "Oldest contact will now be erased when u create new contact coz no memory enough" << std::endl;
		p->ContactIndex = 0;
	}
	p->ContactList[p->ContactIndex] = FillContact ();
	if (p->ContactNb != 8)
		p->ContactNb++;
	p->ContactIndex++;
}
