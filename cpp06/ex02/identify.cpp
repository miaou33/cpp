# include "identify.hpp"

int roll (int nb_of_randoms)
{
   srand (time (NULL));
   return rand () % nb_of_randoms;
}

Base    *generate (void) {

    int random = roll (3);

    switch (random) {
        case 0:
            display ("Class A generated");
            return new A ();
        case 1:
            display ("Class B generated");
            return new B ();
        case 2:
            display ("Class C generated");
            return new C ();
        default:
            return NULL;
    }
}

void    identify (Base *b) {

    if (dynamic_cast <A*> (b) != NULL)
        std::cout << "Pointer to class A identified" << std::endl;
    else if (dynamic_cast <B*> (b) != NULL)
        std::cout << "Pointer to class B identified" << std::endl;
    else if (dynamic_cast <C*> (b) != NULL)
        std::cout << "Pointer to class C identified" << std::endl;
}

void    identify (Base &b) {

    try {
        (void) dynamic_cast <A&> (b);
        std::cout << "Reference to class A identified" << std::endl;
    }
    catch (std::bad_cast& e) {}

    try {
        (void) dynamic_cast <B&> (b);
        std::cout << "Reference to Class B identified" << std::endl;
    }
    catch (std::bad_cast& e) {}

    try {
        (void) dynamic_cast <C&> (b);
        std::cout << "Reference to Class C identified" << std::endl;
    }
    catch (std::bad_cast& e) {}
}