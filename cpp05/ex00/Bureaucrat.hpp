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
		int					_grade;
		static const int	_highest_grade = 1;
		static const int	_lowest_grade = 150;

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Bureaucrat (std::string const name, int grade);
		Bureaucrat (Bureaucrat const& original);
		virtual ~Bureaucrat ();
		Bureaucrat& operator= (Bureaucrat const& rhs);

		// GETTERS SETTERS
		std::string const&	getName () const;
		int const&			getGrade () const;
		void				lowerGrade ();
		void				upperGrade ();

		// NESTED EXCEPTIONS
		class Exception : public std::exception {

			public:
				virtual const char* what() const throw();

		};
		class GradeTooHighException : public Bureaucrat::Exception {

			public:
				virtual const char* what() const throw();

		};
		class GradeTooLowException : public Bureaucrat::Exception {

			public:
				virtual const char* what() const throw();

		};


};

std::ostream&	operator<< (std::ostream& ostream, Bureaucrat const& toDisplay);

# endif