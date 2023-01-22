/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjeiwjifeoh <fjeiwjifeoh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:12:17 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/21 18:20:07 by fjeiwjifeoh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

enum e_InfTitles {firstname, lastname, nickname, number, secret};

class	Contact {

	public:
		// VARIABLES
		std::string	Infos[5];

		// METHODS
		void	PrintInfosTitles (size_t index);
		void	PrintOneContact (Contact c);

};

#endif