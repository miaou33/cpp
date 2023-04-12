#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <cstdlib>
# include <exception>
# include <typeinfo>

# include "utils.hpp"
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base    *generate (void);
void    identify (Base *b);
void    identify (Base &b);

#endif