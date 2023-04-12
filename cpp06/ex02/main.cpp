#include "identify.hpp"

int	main (void)
{
    Base    *random = generate ();
    identify (random);
    Base    &randomREF = *random;
    identify (randomREF);
    delete random;
    return 0;
}