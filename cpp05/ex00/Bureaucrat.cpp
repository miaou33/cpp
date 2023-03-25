# include "Bureaucrat.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Bureaucrat::Bureaucrat (std::string const name, int grade) : _name (name) {

	checkGrade (grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat (Bureaucrat const& original) : _name (original.getName ()) {

	*this = original;
}

Bureaucrat::~Bureaucrat () {}

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& rhs) {

	std::cout << "Warning : name not assigned to '" << rhs.getName () << "' coz name is const" << std::endl;
	_grade = rhs.getGrade ();
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																					  */
/******************************************************************************************************/

std::string const&	Bureaucrat::getName () const {

	return ((std::string const &) _name);
}

int const&			Bureaucrat::getGrade () const {

	return ((int const &) _grade);
}

void				Bureaucrat::lowerGrade () {

	checkGrade (++_grade);
}

void				Bureaucrat::upperGrade () {

	checkGrade (--_grade);
}

/******************************************************************************************************/
/*	OTHER MB FUNCTIONS																				  */
/******************************************************************************************************/

void		Bureaucrat::checkGrade (int grade) const {

	if (grade < _highest_grade)
		throw Bureaucrat::GradeTooHighException ();
	else if (grade > _lowest_grade)
		throw Bureaucrat::GradeTooLowException ();
}

const char*	Bureaucrat::GradeTooHighException::what () const throw () {

	return ("Grade lesser than 1 doesnt exist. 1 is maximum");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw () {

	return ("Grade after 150 doesnt exist. 150 is the minimum");
}

/******************************************************************************************************/
/*	NON MB FUNCTIONS																				  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, Bureaucrat const& toDisplay) {

	o << toDisplay.getName () << ", bureaucrat grade " << toDisplay.getGrade ();
	return o;
}