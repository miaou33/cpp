# include "serialization.hpp"

uintptr_t   serialize (Data *ptr) {

    if (!ptr)
        return 0;
    return reinterpret_cast <uintptr_t> (ptr);
}

Data        *deserialize (uintptr_t raw) {

    if (!raw)
        return NULL;
    return reinterpret_cast <Data*> (raw);
}