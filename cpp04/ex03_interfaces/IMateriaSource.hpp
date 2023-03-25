#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

	public:
	 	// DESTRUCTOR
		virtual ~IMateriaSource () {}

		// OTHER MB FUNCTIONS
		virtual void		learnMateria (AMateria *) = 0;
		virtual AMateria*	createMateria (std::string const& type) = 0;
};

#endif