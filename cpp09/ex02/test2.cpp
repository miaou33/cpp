#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

// Function to recursively sort half of the elements
void sortHalf(std::vector<int> &S, std::vector<int> &remaining, const std::vector<int> &X) {
    for (size_t i = 0; i < X.size(); i += 2) {
        if (X[i] < X[i + 1]) {
            S.push_back(X[i + 1]);
            remaining.push_back(X[i]);
        } else {
            S.push_back(X[i]);
            remaining.push_back(X[i + 1]);
        }
    }
    std::sort(S.begin(), S.end());
}

// Ford-Johnson sort algorithm
void fordJohnsonSort(std::vector<int> &X) {
    size_t n = X.size();
    if (n <= 1) {
        return;
    }

    std::vector<int> S;
    std::vector<int> remaining;
    sortHalf(S, remaining, X);

    // Insert the smallest element from remaining into S
    int min_remaining = *std::min_element(remaining.begin(), remaining.end());
    std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), min_remaining);
    S.insert(pos, min_remaining);

    // Remove smallest element from remaining
    remaining.erase(std::remove(remaining.begin(), remaining.end(), min_remaining), remaining.end());

    // Insert remaining elements into S based on the computed positions
    for (std::vector<int>::iterator it = remaining.begin(); it != remaining.end(); ++it) {
        pos = std::lower_bound(S.begin(), S.end(), *it);
        S.insert(pos, *it);
    }

    // Copy the sorted elements back to X
    std::copy(S.begin(), S.end(), X.begin());
}

bool isPositiveNumeric (std::string const& s) {

	return (s.find_first_not_of ("0123456789") == std::string::npos);
}

int main(int ac, char **av) {

	if (ac > 1)
	{
		clock_t startTime = clock ();
		std::vector<int> arr;
		for (int i = 1; i < ac; ++i)
		{
			if (!isPositiveNumeric (av [i]))
				std::cerr << "Invalid input. Only positive integers are allowed." << std::endl;

			long long num = std::atoll (av [i]);
			std::cout << "num = " << num << std::endl;
			if (num == 0 || num > std::numeric_limits <int>::max ())
			{
				std::cerr << "Invalid input. Only positive integers are allowed." << std::endl;
				exit (EXIT_FAILURE);
			}
			int elem = static_cast <int> (num);
			arr.push_back (elem);
		}
		fordJohnsonSort(arr);
		
		// Print sorted array
		for (size_t i = 0; i < arr.size(); ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		clock_t endTime = clock ();
		return static_cast <double> (endTime - startTime) / CLOCKS_PER_SEC * 1000000.0;
	}
    
    return 0;
}

