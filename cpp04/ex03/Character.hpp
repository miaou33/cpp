#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : virtual public ICharacter {

	private:
		std::string	_name;
		AMateria	**_materias;
	
	public:
		Character (std::string name);
		Character (Character const& original);
		virtual ~Character ();
		Character& operator= (Character const& source);

		virtual std::string const& getName () const;

		virtual void equip (AMateria* m);
		virtual void unequip (int idx);
		virtual void use (int idx, ICharacter& target);
};

#endif