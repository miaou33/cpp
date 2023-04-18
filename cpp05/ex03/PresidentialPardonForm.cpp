# include "PresidentialPardonForm.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

PresidentialPardonForm::PresidentialPardonForm () : 
		AForm ("PresidentialPardonForm", "Nobody", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm (std::string target) :
		AForm ("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const& original) :
		AForm (original) {}

PresidentialPardonForm::~PresidentialPardonForm () {}

PresidentialPardonForm& PresidentialPardonForm::operator= (PresidentialPardonForm const& rhs) {

	if (this != &rhs)
		std::cout << "Warning : attributes cant be assigned coz they are const\nAssignation not done" << std::endl;
	return *this;
}

/******************************************************************************************************/
/*	METHODS																							  */
/******************************************************************************************************/

void				PresidentialPardonForm::execute (Bureaucrat const& executor) {

	AForm::checkExecutability (executor);
	std::cout << "Zaphod Beeblebrox forgave " << AForm::getTarget () << std::endl;
}
