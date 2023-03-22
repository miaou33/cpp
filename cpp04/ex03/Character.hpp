#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : virtual public ICharacter {

	private:
		std::string			_name;
		static const int	_bag_max = 4;
		int					_nb_equiped;
		AMateria			*_bag [_bag_max];
	
	public:
		Character (std::string name);
		Character (Character const& original);
		virtual ~Character ();
		Character& operator= (Character const& source);

		virtual std::string const&	getName () const;
		AMateria 					*getMateria (int i) const;

		bool			is_in_bag (int i) const;
		virtual void	equip (AMateria* m);
		virtual void	unequip (int idx);
		virtual void	use (int idx, ICharacter& target);
};

#endif