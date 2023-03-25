#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "colors.hpp"

class Bureaucrat {

	public:

		Bureaucrat (std::string const name, int grade);
		Bureaucrat (Bureaucrat const& original);
		virtual ~Bureaucrat ();
		Bureaucrat& operator= (Bureaucrat const& rhs);

		std::string const&	getName () const;
		int const&			getGrade () const;
		void				lowerGrade ();
		void				upperGrade ();

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();

		};
		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();

		};
		static const int	highest_grade = 1;
		static const int	lowest_grade = 150;
		static bool			verbose;


	private:

		std::string const	_name;
		int					_grade;

		void				announce (std::string const func) const;
		void				checkGrade (int grade) const;

};

std::ostream&	operator<< (std::ostream& ostream, Bureaucrat const& toDisplay);

# endif