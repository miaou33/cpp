#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

template <typename Container>
void displayContainer(const Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename Container>
double mergeInsertSort(Container& container)
{
    clock_t startTime = clock();

    //typedef typename Container::value_type ValueType;
    typedef typename Container::iterator Iterator;

    Container sortedContainer;

    for (Iterator it = container.begin(); it != container.end(); ++it)
    {
        Iterator sortedIt = std::upper_bound(sortedContainer.begin(), sortedContainer.end(), *it);
        sortedContainer.insert(sortedIt, *it);
    }

    container = sortedContainer;

    clock_t endTime = clock();
    return static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000000.0;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Error: No positive integer sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vecContainer;
    std::list<int> listContainer;

    for (int i = 1; i < argc; ++i)
    {
        int value = std::atoi(argv[i]);
        if (value > 0)
        {
            vecContainer.push_back(value);
            listContainer.push_back(value);
        }
        else
        {
            std::cout << "Error: Invalid input. Only positive integers are allowed." << std::endl;
            return 1;
        }
    }

    std::cout << "Before: ";
    displayContainer(vecContainer);

    std::cout << "After:" << std::endl;

    std::cout << "Using std::vector: ";
    double vecTime = mergeInsertSort(vecContainer);
    displayContainer(vecContainer);
    std::cout << "Time to process a range of " << vecContainer.size() << " elements with std::vector: " << vecTime << " us" << std::endl;

    std::cout << "Using std::list: ";
    double listTime = mergeInsertSort(listContainer);
    displayContainer(listContainer);
    std::cout << "Time to process a range of " << listContainer.size() << " elements with std::list: " << listTime << " us" << std::endl;

    return 0;
}

