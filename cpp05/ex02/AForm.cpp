# include "AForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

AForm::AForm () :	

	_name ("Void form"),
	_target ("Nobody"),
	_grade_to_sign (Bureaucrat::highest_grade),
	_grade_to_execute (Bureaucrat::highest_grade)
{
	_is_signed = 0;
}

AForm::AForm (std::string name, std::string const& target, int sign_grade, int exec_grade) :

	_name (name),
	_target (target),
	_grade_to_sign (sign_grade),
	_grade_to_execute (exec_grade)
{
	_is_signed = 0;
	checkGrade (_grade_to_sign);
	checkGrade (_grade_to_execute);
}

AForm::AForm (AForm const& original) :

	_name (original.getName ()),
	_target (original.getTarget ()),
	_grade_to_sign (original.getSignGrade ()),
	_grade_to_execute (original.getExecGrade ())
{
	_is_signed = (bool) original.isSigned ();
}

AForm::~AForm () {}

AForm& AForm::operator= (AForm const& rhs) {

	if (this != &rhs)
		std::cout << "Warning : attributes cant be assigned coz they are const\nAssignation not done" << std::endl;
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

std::string const&	AForm::getName () const {

	return (std::string const &)_name;
}

std::string const&	AForm::getTarget () const {

	return (std::string const&) _target;
}

bool				AForm::isSigned () const {

	return _is_signed;
}

int					AForm::getSignGrade () const {

	return (int const&) _grade_to_sign;
}

int					AForm::getExecGrade () const {

	return (int const&) _grade_to_execute;
}

void				AForm::beSigned (Bureaucrat const& bureaucrat) {

	bureaucrat.getGrade () <= _grade_to_sign ?
		_is_signed = true
		: throw AForm::GradeTooLowException ();
}

void				AForm::checkExecutability (Bureaucrat const& executor) {

	if (!_is_signed)
		throw AForm::FormNotSignedException ();
	if (executor.getGrade () > _grade_to_execute)
		throw AForm::GradeTooLowException ();
}

/******************************************************************************************************/
/*	PRIVATE UTILS 																					  */
/******************************************************************************************************/

void	AForm::checkGrade (int grade) const {

	if (grade < Bureaucrat::highest_grade)
		throw AForm::GradeTooHighException ();
	else if (grade > Bureaucrat::lowest_grade)
		throw AForm::GradeTooLowException ();
}

void		AForm::announce (std::string const func) const {

	std::cout << _GREY << func << ": " << _name << " form, grade needed to sign : " << _grade_to_sign << " | grade needed to exec : " << _grade_to_execute << _END << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	AForm::GradeTooHighException::what () const throw () {

	return ("\033[31mForm exception reeched\033[0m: Bureaucrat's grade too high");
}

const char*	AForm::GradeTooLowException::what () const throw () {

	return ("\033[31mForm exception reeched\033[0m: Bureaucrat's grade too low\033[0m");
}

const char*	AForm::FormNotSignedException::what () const throw () {

	return ("\033[31mForm exception reeched\033[0m: cannot be executed coz not signed");
}

/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, AForm const& toDisplay) {

	o << toDisplay.getName () << " form, grade needed to sign : " << toDisplay.getSignGrade () << " | grade needed to exec : " << toDisplay.getExecGrade () << std::endl;
	return o;
}

