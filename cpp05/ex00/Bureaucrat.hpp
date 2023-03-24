#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

typedef unsigned long t_ul;
typedef unsigned int t_ui;
typedef long long t_ll;

class Bureaucrat {

	private:
		std::string const	_name;
		__uint8_t			_grade;

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Bureaucrat (std::string const name, t_ll grade);
		Bureaucrat (Bureaucrat const& original);
		virtual ~Bureaucrat ();
		Bureaucrat& operator= (Bureaucrat const& toBecome);

		// GETTERS SETTERS
		std::string const&	getName () const;
		__uint8_t const&	getGrade () const;
		void				lowerGrade ();
		void				upperGrade ();

		// MEMBER FUNCTIONS

};

std::ostream&	operator<< (std::ostream const& ostream, Bureaucrat const& toDisplay);

# endif