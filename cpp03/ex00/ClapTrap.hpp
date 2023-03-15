#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>
# include <iostream>
# include <limits.h>
# include "colors.hpp"

typedef unsigned long t_ul;
typedef unsigned int t_ui;
typedef long long t_ll;

class	ClapTrap {

	private:
		std::string		_name;
		t_ui			_HP;
		t_ui			_maxHP;
		t_ui			_PP;
		t_ui			_AD;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		ClapTrap ();
		ClapTrap (std::string name);
		ClapTrap (ClapTrap const& original);
		~ClapTrap ();
	 
	 	// OPERATORS
		ClapTrap&	operator= (ClapTrap const& source);
		
		// GETTERS / SETTERS
		std::string const	getName () const;
		t_ui				getHP () const;
		t_ui				getPP () const;
		t_ui				getAD () const;

		// OTHERS
		void				attack (const std::string& target);
		void				takeDamage (t_ui amount);
		void				beRepaired (t_ui amount);
		void				printStats ();
		
};

#endif