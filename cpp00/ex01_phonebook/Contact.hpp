/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:12:17 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/26 18:42:14 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

enum e_InfTitles {firstname, lastname, nickname, number, secret};

class	Contact {

	private:
		// VARIABLES
		std::string	Infos[5];

	public:
		// METHODS
		void	FillContact (void);
		void	PrintFullContact (void);
		void	PrintFormatContact (void);
		void	PrintInfosTitles (size_t index);
};

#endif