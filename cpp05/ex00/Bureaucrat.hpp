#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "colors.hpp"

class Bureaucrat {

	public:

		Bureaucrat ();
		Bureaucrat (std::string const name, int grade);
		Bureaucrat (Bureaucrat const& original);
		~Bureaucrat ();
		Bureaucrat& operator= (Bureaucrat const& rhs);

		static int const	highest_grade = 1;
		static int const	lowest_grade = 150;

		std::string const&	getName () const;
		int const&			getGrade () const;
		void				lowerGrade ();
		void				upperGrade ();

	private:

		std::string const	_name;
		int					_grade;
		static bool			_verbose;

		void				announce (std::string const func) const;
		void				checkGrade (int grade) const;

	public:

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();

		};
		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();

		};

};

std::ostream&	operator<< (std::ostream& ostream, Bureaucrat const& toDisplay);

# endif
