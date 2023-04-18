# include "Form.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Form::Form () :

	_name ("Void form"),
	_grade_to_sign (Bureaucrat::highest_grade),
	_grade_to_execute (Bureaucrat::highest_grade)
{
	_is_signed = 0;
}

Form::Form (std::string name, int sign_grade, int exec_grade) :

	_name (name),
	_grade_to_sign (sign_grade),
	_grade_to_execute (exec_grade)
{
	_is_signed = 0;
	checkGrade (_grade_to_sign);
	checkGrade (_grade_to_execute);
}

Form::Form (Form const& original) :

	_name (original.getName ()),
	_grade_to_sign (original.getSignGrade ()),
	_grade_to_execute (original.getExecGrade ())
{
	_is_signed = (bool) original.isSigned ();
}

Form::~Form () {}

Form& Form::operator= (Form const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned coz it is const" << std::endl;
		std::cout << "Warning : sign grade not assigned coz it is const" << std::endl;
		std::cout << "Warning : exec grade not assigned coz it is const" << std::endl;
		_is_signed = rhs.isSigned ();
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

std::string const&	Form::getName () const {

	return (std::string const &)_name;
}

bool const&			Form::isSigned () const {

	return (bool const &) _is_signed;
}

int	const&			Form::getSignGrade () const {

	return (int const&) _grade_to_sign;
}

int const&			Form::getExecGrade () const {

	return (int const&) _grade_to_execute;
}

void				Form::beSigned (Bureaucrat const& bureaucrat) {

	bureaucrat.getGrade () <= _grade_to_sign ?
		_is_signed = true
		: throw Form::GradeTooLowException ();
}

/******************************************************************************************************/
/*	PRIVATE UTILS 																					  */
/******************************************************************************************************/

void	Form::checkGrade (int grade) const {

	if (grade < Bureaucrat::highest_grade)
		throw Form::GradeTooHighException ();
	else if (grade > Bureaucrat::lowest_grade)
		throw Form::GradeTooLowException ();
}

void		Form::announce (std::string const func) const {

	std::cout << _GREEN << func << _END 
		<< ": " << _name << " form, grade needed to sign : " << _grade_to_sign << " | grade needed to exec : " << _grade_to_execute << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	Form::GradeTooHighException::what () const throw () {

	return ("\033[31mForm exception reeched\033[0m: Bureaucrat's grade too high");
}

const char*	Form::GradeTooLowException::what () const throw () {

	return ("\033[31mForm exception reeched\033[0m: Bureaucrat's grade too low");
}

/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, Form const& toDisplay) {

	o << toDisplay.getName () << " form, grade needed to sign : " << toDisplay.getSignGrade () << " | grade needed to exec : " << toDisplay.getExecGrade () << std::endl;
	return o;
}

