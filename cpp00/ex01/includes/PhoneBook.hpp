/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:20:05 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/22 17:07:44 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class	PhoneBook {

	public:
		//VARIABLES
		size_t	ContactNb;
		size_t	ContactIndex;
		Contact	ContactList[8];

		//METHOD
		void	LaunchPhoneBook (PhoneBook p);
		void	PrintContactElem (Contact c);
		void	AddContact (PhoneBook *p);
		void	SearchContact (PhoneBook p);};

#endif