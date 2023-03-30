#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : virtual public AForm {

	public:
		ShrubberyCreationForm ();
		ShrubberyCreationForm (std::string target);
		ShrubberyCreationForm (ShrubberyCreationForm const& original);
		virtual ~ShrubberyCreationForm ();
		ShrubberyCreationForm& operator= (ShrubberyCreationForm const& rhs);

		std::string const&	getTarget () const;
		virtual void		execute (Bureaucrat const& executor);

		class FileOpeningFailed : public std::exception {

			public:
				virtual const char* what() const throw();

		};

	private:
		std::string			_target;
};

# endif