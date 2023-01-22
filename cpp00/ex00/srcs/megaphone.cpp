/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjeiwjifeoh <fjeiwjifeoh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:12:25 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/21 18:20:13 by fjeiwjifeoh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//using namespace std;

int	main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (size_t i = 1; av[i]; i++)
	{
		std::string	str (av[i]);
		for (int j = str.length (); j >= 0; j--)
			str[j] = toupper (str[j]);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
