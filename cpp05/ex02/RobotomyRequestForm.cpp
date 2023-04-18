# include "RobotomyRequestForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

RobotomyRequestForm::RobotomyRequestForm () :
		AForm ("RobotomyRequestForm", "Nobody", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm (std::string target) :
		AForm ("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const& original) :
		AForm (original) {}

RobotomyRequestForm::~RobotomyRequestForm () {}

RobotomyRequestForm& RobotomyRequestForm::operator= (RobotomyRequestForm const& rhs) {

	if (this != &rhs)
		std::cout << "Warning : attributes cant be assigned coz they are const\nAssignation not done" << std::endl;
	return *this;
}

/******************************************************************************************************/
/*	METHODS																							  */
/******************************************************************************************************/

void				RobotomyRequestForm::execute (Bureaucrat const& executor) {

	AForm::checkExecutability (executor);
	std::cout << "* Drill noise ....... *" << std::endl;
	srand (time (NULL));
	if (rand () % 2)
		std::cout << AForm::getTarget () << " successfully robotomized :O" << std::endl;
	else
		throw RobotomyRequestForm::RobotomyFailed ();
}

/******************************************************************************************************/
/*	EXCEPTIONS 																						  */
/******************************************************************************************************/

const char*	RobotomyRequestForm::RobotomyFailed::what () const throw () {

	return ("\033[31mRobotomy exception reeched\033[0m: robotomy failed sorry");
}

