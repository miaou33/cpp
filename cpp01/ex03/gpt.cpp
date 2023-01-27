#include <string>
#include <iostream>

class	Weapon {

	private:
		std::string	_type;

	public:
		Weapon ();
		Weapon (std::string type);
		const std::string	&getType (void);
		void				setType (std::string type);

};

class	HumanA {

	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA (std::string name, Weapon &weapon);
		void	attack ();

};

HumanA::HumanA (std::string name, Weapon &weapon) {
	_name = name;
	_weapon = weapon;
}

void	HumanA::attack ()
{
	std::cout << _name << " attacks with their " << _weapon.getType () << std::endl;
}

int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	return 0;
}