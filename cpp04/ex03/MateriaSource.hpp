#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:
		static const int	_source_max = 4;
		AMateria*			_source [_source_max];

	public:
		MateriaSource ();
		MateriaSource (MateriaSource const& original);
		MateriaSource& operator= (MateriaSource const& source);
		virtual ~MateriaSource ();

		// MEMBER FUNCTIONS
		virtual void		learnMateria (AMateria *);
		virtual AMateria*	createMateria (std::string const& type);
};

#endif