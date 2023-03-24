# include "Bureaucrat.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Bureaucrat::Bureaucrat (std::string const name, t_ll grade) : _name (name) {

	try {
		if (grade < 1 || grade > 150)
			throw grade;
		else
			_grade = (__uint8_t) grade;
	}
	catch (t_ull& exception) {

	}
}

Bureaucrat::Bureaucrat (Bureaucrat const& original) {}

Bureaucrat::~Bureaucrat () {}

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& toBecome) {

}

/******************************************************************************************************/
/*	GETTERS SETTERS																					  */
/******************************************************************************************************/

std::string const&	Bureaucrat::getName () const {}

__uint8_t const&	Bureaucrat::getGrade () const {}

void				Bureaucrat::lowerGrade () {}

void				Bureaucrat::upperGrade () {}

/******************************************************************************************************/
/*	MEMBER FUNCTIONS																				  */
/******************************************************************************************************/

/******************************************************************************************************/
/*	OTHERS																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream ostream, Bureaucrat const& toDisplay) {

	ostream << toDisplay.getName () << ", bureaucrat grade " << toDisplay.getGrade ();
	return ostream;
}