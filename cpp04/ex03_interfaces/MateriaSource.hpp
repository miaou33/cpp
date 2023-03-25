#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:
		static const int	_materia_source_max = 4;
		int					_nb_learned;
		AMateria*			_materia_source [_materia_source_max];

	public:
	 	// CONSTRUCTOR DESTRUCTOR ASSIGNMENT
		MateriaSource ();
		MateriaSource (MateriaSource const& original);
		virtual ~MateriaSource ();
		MateriaSource& operator= (MateriaSource const& rhs);

		// GETTER
		AMateria 			*getMateria (int i) const;

		// OTHER MB FUNCTIONS
		bool				is_in_source (int i) const;
		virtual void		learnMateria (AMateria *);
		virtual AMateria*	createMateria (std::string const& type);
};

#endif