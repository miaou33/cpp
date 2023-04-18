#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : virtual public AForm {

	public:
		RobotomyRequestForm ();
		RobotomyRequestForm (std::string target);
		RobotomyRequestForm (RobotomyRequestForm const& original);
		virtual ~RobotomyRequestForm ();
		RobotomyRequestForm& operator= (RobotomyRequestForm const& rhs);

		virtual void		execute (Bureaucrat const& executor);

		class RobotomyFailed : public std::exception {
			public: virtual const char* what() const throw(); };
};

# endif
