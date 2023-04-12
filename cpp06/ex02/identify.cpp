# include "identify.hpp"

int roll (int min, int max)
{
   // x is in [0,1[
   double x = rand()/static_cast<double>(RAND_MAX+1); 

   // [0,1[ * (max - min) + min is in [min,max[
   int that = min + static_cast<int>( x * (max - min) );

   return that;
}

Base    *generate (void) {

    int random = roll (0, 2);

    switch (random) {
        case 0:
            return new A ();
        case 1:
            return new B ();
        case 2:
            return new C ();
        default:
            return NULL;
    }
}

void    identify (Base *b) {

(void) b;
}

void    identify (Base &b) {


(void) b;
}