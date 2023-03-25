#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {

	public:
		Form (std::string name, int signing_grade, int exec_grade);
		Form (Form const& original);
		virtual ~Form ();
		Form& operator= (Form const& rhs);

		std::string const&	getName () const;
		bool const&			isSigned () const;
		int	const&			getSignGrade () const;
		int const&			getExecGrade () const;

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
		int					_sign_grade;
		int					_exec_grade;

		void				checkGrade (int grade) const;
};

std::ostream&	operator<< (std::ostream& o, Form const& rhs);

# endif