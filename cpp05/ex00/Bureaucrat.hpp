#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {

	private:
		std::string	_name;
		__uint8_t	_grade;

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Bureaucrat ();
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


# endif