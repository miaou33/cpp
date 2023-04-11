#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

typedef struct s_data {

    std::string     s;
    int             i;
    std::string     *ptr;
}               Data;

#endif