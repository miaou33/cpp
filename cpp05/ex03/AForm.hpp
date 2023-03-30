#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm ();
		AForm (std::string name, int sign_grade, int exec_grade);
		AForm (AForm const& original);
		virtual ~AForm ();
		AForm& operator= (AForm const& rhs);

		std::string const&				getName () const;
		virtual std::string const&		getTarget () const = 0;
		bool const&						isSigned () const;
		void							checkExecutability (Bureaucrat const& bureaucrat);
		int	const&						getSignGrade () const;
		int const&						getExecGrade () const;

		virtual void					beSigned (Bureaucrat const& bureaucrat);
		virtual void					execute (Bureaucrat const& executor) = 0;

	protected:
		std::string const				_name;
		bool							_is_signed;
		int	const						_grade_to_sign;
		int	const						_grade_to_execute;
		static const bool				_verbose = false;

		virtual void					checkGrade (int grade) const;
		virtual void					announce (std::string const func) const;
	
	public:

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
};

std::ostream&	operator<< (std::ostream& o, AForm const& rhs);

# endif