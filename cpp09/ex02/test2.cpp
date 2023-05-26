#include <iostream>
#include <vector>
#include <list>

template<typename Container>
void merge(Container& arr, typename Container::iterator left, typename Container::iterator mid, typename Container::iterator right) {

	(void)arr;
    Container L(left, mid);
    Container R(mid, right);

    typename Container::iterator it1 = L.begin();
    typename Container::iterator it2 = R.begin();
    typename Container::iterator it = left;

    while (it1 != L.end() && it2 != R.end()) {
        if (*it1 <= *it2) {
            *it = *it1;
            it1++;
        } else {
            *it = *it2;
            it2++;
        }
        it++;
    }

    while (it1 != L.end()) {
        *it = *it1;
        it1++;
        it++;
    }

    while (it2 != R.end()) {
        *it = *it2;
        it2++;
        it++;
    }
}

template<typename Container>
double mergeInsertionSort(Container& arr, typename Container::iterator left, typename Container::iterator right) {

    clock_t startTime = clock();
     if (std::distance(left, right) > 1) {
        if (std::distance(left, right) <= 5) {
			 typename Container::iterator it = left;
            for (int i = 0; i < std::distance(left, right); i++) {
                typename Container::value_type key = *it;
                typename Container::iterator j = it;
                while (j != left && *(std::advance(j, -1)) > key) {
                    *j = *(std::advance(j, -1));
                    std::advance(j, -1);
                }
                *j = key;
                it++;
            }
        } else {
			 typename Container::iterator mid = left;
            std::advance(mid, std::distance(left, right) / 2);
            mergeInsertionSort(arr, left, mid);
            mergeInsertionSort(arr, mid, right);
            merge(arr, left, mid, right);
        }
	 }
	clock_t endTime = clock();
    return static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000000.0;
}

template<typename Container>
void printContainer(const Container& arr) {
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Usage: ./a.out <integer list>" << std::endl;
        return 0;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; i++) {
        int num = std::stoi(argv[i]);
        vec.push_back(num);
        lst.push_back(num);
    }

    double vecTime = mergeInsertionSort(vec, vec.begin(), vec.end());
    std::cout << "Sorted vector: ";
    printContainer(vec);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime << " us" << std::endl;

	std::cout << std::endl;

    double listTime = mergeInsertionSort(lst, lst.begin(), lst.end());
    std::cout << "Sorted list: ";
    printContainer(lst);
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << listTime << " us" << std::endl;

    return 0;
}

