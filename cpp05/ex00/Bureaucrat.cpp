# include "Bureaucrat.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Bureaucrat::Bureaucrat () : _name ("No name") {

	_grade = lowest_grade;
}

Bureaucrat::Bureaucrat (std::string const name, int grade) :

	_name (name) 
{
	checkGrade (grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat (Bureaucrat const& original) :

	_name (original.getName ())
{
	_grade = original.getGrade ();
}

Bureaucrat::~Bureaucrat () {}

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned to '" << rhs.getName () << "' coz name is const" << std::endl;
		_grade = rhs.getGrade ();
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																					  */
/******************************************************************************************************/

std::string const&	Bureaucrat::getName () const {

	return (_name);
}

int					Bureaucrat::getGrade () const {

	return (_grade);
}

void				Bureaucrat::lowerGrade () {

	std::cout << "Lowering grade of " << _name << "..." << std::endl;
	checkGrade (_grade + 1);
	_grade++;
	announce ("Lowered grade");
}

void				Bureaucrat::upperGrade () {

	std::cout << "Uppering grade of " << _name << "..." << std::endl;
	checkGrade (_grade - 1);
	_grade--;
	announce ("Uppered grade");
}

/******************************************************************************************************/
/*	PRIVATE UTILS																					  */
/******************************************************************************************************/

void		Bureaucrat::checkGrade (int grade) const {

	if (grade < highest_grade)
		throw Bureaucrat::GradeTooHighException ();
	else if (grade > lowest_grade)
		throw Bureaucrat::GradeTooLowException ();
}

void		Bureaucrat::announce (std::string const func) const {

	std::cout << _GREEN << func << _END 
		<< ": " << _name << " bureaucrat, grade " << _grade << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

const char*	Bureaucrat::GradeTooHighException::what () const throw () {

	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw () {

	return ("Grade too low");
}

/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, Bureaucrat const& toDisplay) {

	o << toDisplay.getName () << ", bureaucrat grade " << toDisplay.getGrade ();
	return o;
}

