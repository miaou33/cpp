#include "data.hpp"
#include "serialization.hpp"

int    main ()
{
    Data  data;

    data.s = "test";
    data.i = 43;
    data.ptr = &data.s;

    std::cout << std::endl;
    std::cout << "Before serialization :" << std::endl;
    std::cout << data.s << std::endl;
    std::cout << data.i << std::endl;
    std::cout << data.ptr << std::endl;
    std::cout << std::endl;

    uintptr_t   raw = serialize (&data);
    deserialize (raw);

    std::cout << "After serialization :" << std::endl;
    std::cout << data.s << std::endl;
    std::cout << data.i << std::endl;
    std::cout << data.ptr << std::endl;
    std::cout << std::endl;

    return 0;
}