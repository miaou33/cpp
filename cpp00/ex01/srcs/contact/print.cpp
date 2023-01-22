/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:12:23 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/22 17:12:06 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::PrintOneContact (Contact c)
{
 	for (size_t i = 0; i < 5; i++)
	{
		c.PrintInfosTitles(i);
		std::cout << c.Infos[i] << std::endl;
	}
}

void	Contact::PrintInfosTitles (size_t index)
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