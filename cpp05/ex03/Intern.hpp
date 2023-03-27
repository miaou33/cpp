#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include <exception>
# include "colors.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern {

	public:

		Intern ();
		Intern (Intern const& original);
		virtual ~Intern ();
		Intern& operator= (Intern const& rhs);

		AForm*						makeForm (std::string form_name, std::string target);

	private:
		static const bool			_verbose = false;
		void						announce (std::string const func) const;

	public:
	
		class FormNotMakable : public std::exception {

			public:
				virtual const char*	what () const throw ();
		};

};

# endif