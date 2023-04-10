#ifndef NCLASS_HPP
# define NCLASS_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class nClass {

    public:
        // CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
        nClass ();
        nClass (nClass const& original);
        virtual ~nClass ();
        nClass& operator= (nClass const& rhs);

        // GETTER

        // OTHER MB FUNCTIONS

};


# endif