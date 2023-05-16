#include "MutantStack.hpp"
#include <vector>

int	main (void)
{
    MutantStack<int> mstack;
    mstack.push (1);
    mstack.push (20);
    std::cout << mstack.top () << std::endl;
    mstack.pop ();
    std::cout << mstack.size () << std::endl;
    mstack.push (0);
    mstack.push (5);
    mstack.push (2999);
    mstack.push (-100);
    MutantStack<int>::iterator it = mstack.begin ();
    MutantStack<int>::iterator ite = mstack.end ();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

	std::cout << std::endl;

	std::vector<int> v;
    v.push_back (1);
    v.push_back (20);
    std::cout << v.back () << std::endl;
    v.pop_back ();
    std::cout << v.size () << std::endl;
    v.push_back (0);
    v.push_back (5);
    v.push_back (2999);
    v.push_back (-100);
    std::vector<int>::iterator vit = v.begin ();
    std::vector<int>::iterator vite = v.end ();
    ++vit;
    --vit;
    while (vit != vite)
    {
        std::cout << *vit << std::endl;
        ++vit;
    }
    return 0;
}
