#include "identify.hpp"

int	main (void)
{
    Base    *random = generate ();

    delete random;
    return 0;
}