/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:20:05 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/22 21:49:17 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class	PhoneBook {

	private:
		//VARIABLES
		size_t	ContactNb;
		Contact	ContactList[8];

	public:
		//METHOD
		PhoneBook ();
		void		LaunchPhoneBook ();
		void		AddContact ();
		void		SearchContact ();
		void		PrintContactList ();
		u_int8_t	GetIndex();
};

#endif