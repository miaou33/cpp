#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm ();
		AForm (std::string name, std::string const& target, int sign_grade, int exec_grade);
		AForm (AForm const& original);
		virtual ~AForm ();
		AForm& operator= (AForm const& rhs);

		std::string const&	getName () const;
		bool				isSigned () const;
		int					getSignGrade () const;
		int					getExecGrade () const;
		std::string const&	getTarget () const;

		virtual void		beSigned (Bureaucrat const& bureaucrat);
		virtual void		execute (Bureaucrat const& executor) = 0;
		void				checkExecutability (Bureaucrat const& bureaucrat);

		class GradeTooHighException : public std::exception {

			public:
				virtual const char*	what () const throw ();
		};
		class GradeTooLowException : public std::exception {

			public:
				virtual const char*	what () const throw ();
		};
		class FormNotSignedException : public std::exception {

			public:
				virtual const char*	what () const throw ();
		};

	private:
		std::string const	_name;
		std::string const	_target;
		int	const			_grade_to_sign;
		int	const			_grade_to_execute;
		bool				_is_signed;

		static const bool	_verbose = false;
		virtual void		checkGrade (int grade) const;
		virtual void		announce (std::string const func) const;
};

std::ostream&	operator<< (std::ostream& o, AForm const& rhs);

# endif
