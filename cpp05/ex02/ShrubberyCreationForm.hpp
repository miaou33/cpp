#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : virtual public AForm {

	public:
		ShrubberyCreationForm (std::string target);
		ShrubberyCreationForm (ShrubberyCreationForm const& original);
		virtual ~ShrubberyCreationForm ();
		ShrubberyCreationForm& operator= (ShrubberyCreationForm const& rhs);

		std::string const&	getTarget () const;
		virtual void		execute (Bureaucrat const& executor);

	private:
		std::string			_target;
};

std::ostream&	operator<< (std::ostream& o, ShrubberyCreationForm const& rhs);

# endif