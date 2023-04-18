#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
	 	Form ();
		Form (std::string name, int sign_grade, int exec_grade);
		Form (Form const& original);
		~Form ();
		Form& operator= (Form const& rhs);

		std::string const&	getName () const;
		bool const&			isSigned () const;
		int	const&			getSignGrade () const;
		int const&			getExecGrade () const;

		void				beSigned (Bureaucrat const& bureaucrat);

		class GradeTooHighException : public std::exception {

			public:
				virtual const char*	what () const throw ();
		};
		class GradeTooLowException : public std::exception {

			public:
				virtual const char*	what () const throw ();
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_grade_to_sign;
		int	const			_grade_to_execute;
		static const bool	_verbose = false;

		void				checkGrade (int grade) const;
		void				announce (std::string const func) const;
};

std::ostream&	operator<< (std::ostream& o, Form const& rhs);

# endif
