#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class PresidentialPardonForm : virtual public AForm {

	public:
		PresidentialPardonForm ();
		PresidentialPardonForm (std::string target);
		PresidentialPardonForm (PresidentialPardonForm const& original);
		virtual ~PresidentialPardonForm ();
		PresidentialPardonForm& operator= (PresidentialPardonForm const& rhs);

		std::string const&	getTarget () const;
		virtual void		execute (Bureaucrat const& executor);

	private:
		std::string			_target;
};

# endif
