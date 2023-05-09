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
const_iterator	MutantStack <T>::begin () const { return std::stack <T>::c.begin () }

template <typename T>
const_iterator	MutantStack <T>::end () const { return std::stack <T>::c.end () }

