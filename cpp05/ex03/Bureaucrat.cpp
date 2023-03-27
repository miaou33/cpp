# include "Bureaucrat.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Bureaucrat::Bureaucrat (std::string const name, int grade) : _name (name) {

	checkGrade (grade);
	_grade = grade;
	if (_verbose)
		announce ("Bureaucrat constructor");
}

Bureaucrat::Bureaucrat (Bureaucrat const& original) : _name (original.getName ()) {

	_grade = original.getGrade ();
	if (_verbose)
		announce ("Bureaucrat copy constructor");
}

Bureaucrat::~Bureaucrat () {

	if (_verbose)
		announce ("Bureaucrat destructor");
}

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned to '" << rhs.getName () << "' coz name is const" << std::endl;
		_grade = rhs.getGrade ();
		if (_verbose)
			announce ("Bureaucrat assignment operator");
	}
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

	std::cout << "Lowering grade of " << _name << "..." << std::endl;
	checkGrade (++_grade);
	announce ("Lowered grade");
}

void				Bureaucrat::upperGrade () {

	std::cout << "Uppering grade of " << _name << "..." << std::endl;
	checkGrade (--_grade);
	announce ("Uppered grade");
}

/******************************************************************************************************/
/*	PUBLIC MB FUNC																					  */
/******************************************************************************************************/

void	Bureaucrat::signForm (AForm& form) {

	try {

		form.beSigned (*this);
		std::cout << _PURPLE << _BOLD << "Signed" << _END << ": " << form.getName () << " by bureaucrat " << _name << std::endl;
	}
	catch (std::exception& e) {

		std::cout << _BLUE << _BOLD << "Not signed" << _END << ": " << form.getName () << " by bureaucrat " << _name
					<< ".\n\t-> Cause: " << e.what () << std::endl;
	}
}

void	Bureaucrat::executeForm (AForm& form) const {

	try {
		form.execute (*this);
		std::cout << _PURPLE << _BOLD << "Executed" << _END << ": " << form.getName () << " on " << form.getTarget () << " by bureaucrat " << _name << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _BLUE << _BOLD << "Not executed" << _END << ": " << form.getName () << " by bureaucrat " << _name
					<< ".\n\t-> Cause: " << e.what () << std::endl;
	}
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

	std::cout << _GREY << func 
		<< ": " << _name << " , grade " << _grade << _END << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

const char*	Bureaucrat::GradeTooHighException::what () const throw () {

	return ("Bureaucrat exception reached: Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw () {

	return ("Bureaucrat exception reached: Grade too low");
}

/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, Bureaucrat const& toDisplay) {

	o << _YELLOW << _BOLD << toDisplay.getName () << _END << ", bureaucrat grade " << toDisplay.getGrade ();
	return o;
}
