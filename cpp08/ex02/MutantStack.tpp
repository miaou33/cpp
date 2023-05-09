# include "MutantStack.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

template <typename T>
MutantStack <T>::MutantStack () {}

template <typename T>
MutantStack <T>::MutantStack (MutantStack <T> const& original) { *this = original; }

template <typename T>
MutantStack <T>::~MutantStack () {}

template <typename T>
MutantStack <T>& MutantStack <T>::operator= (MutantStack <T> const& rhs) { return *this; }

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

template <typename T>
typename MutantStack <T>::const_iterator		MutantStack <T>::begin () const { 

	return std::stack <T>::c.begin ();
}

template <typename T>
typename MutantStack <T>::const_iterator		MutantStack <T>::end () const {

	return std::stack <T>::c.end ();
}

template <typename T>
typename MutantStack <T>::iterator		MutantStack <T>::begin () const { 

	return std::stack <T>::c.begin ();
}

template <typename T>
typename MutantStack <T>::iterator		MutantStack <T>::end () const {

	return std::stack <T>::c.end ();
}

