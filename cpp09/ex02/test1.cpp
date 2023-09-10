#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

// Returns the index of the 1st element in the range [start, end) that is < value
// If no such element exists, starts is 
int binarySearch(const std::vector<int> &S, int start, int end, int key) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (S[mid] < key) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

// Function to recursively sort half of the elements
void sortHalf(std::vector<int> &S, const std::vector<int> &X) {
    for (size_t i = 0; i < X.size(); i += 2) {
        S.push_back(std::max(X[i], X[i + 1]));
    }
    std::sort(S.begin(), S.end());
}

// Function for performing the Ford & Johnson algorithm
void fordJohnsonSort(std::vector<int> &X) {
    size_t n = X.size();
    
    // If array is already sorted or empty
    if (n <= 1) {
        return;
    }
    
    std::vector<int> S;  // To hold larger elements of pairs
    std::vector<int> remaining; // To hold the remaining smaller elements of pairs
    std::vector<int> groups; // To hold the special grouping orders
    
    // Step 1, 2, 3: Pair elements, compare and recursively sort
    sortHalf(S, X);
    
    // Step 4: Find smallest element in S and find its pair in X
    int smallestInS = S[0];
    size_t index = std::find(X.begin(), X.end(), smallestInS) - X.begin();
    int pairedSmallest = X[index ^ 1]; // If index is even, index ^ 1 is index+1. Otherwise, it's index-1.
    S.insert(S.begin(), pairedSmallest);
    
    // Step 5, 6, 7: Insert remaining elements into S
    int sum = 2; // Initialize sum to size of first group
    int nextGroup = 2; // Initialize the next group to have 2 elements
    
    for (size_t i = 0; i < n; i++) {
        // Skip elements already in S
        if (std::find(S.begin(), S.end(), X[i]) != S.end()) {
            continue;
        }
        
        remaining.push_back(X[i]);
        
        // Check the next group size by checking if sum is a power of 2
        if ((sum & (sum - 1)) == 0) {
            nextGroup = 2 * sum - nextGroup;
        }
        
        groups.push_back(nextGroup);
        sum += nextGroup;
    }
    
    // Insert remaining elements into S based on groups
    int pos = 0;
	for (std::vector<int>::iterator it = groups.begin(); it != groups.end(); ++it) {
		int groupSize = *it;
        int end = pos + groupSize;
        for (int i = end - 1; i >= pos; --i) {
            int idx = binarySearch(S, 0, pos + 1, remaining[i]);
            S.insert(S.begin() + idx, remaining[i]);
        }
        pos = end;
    }
    
    // Finally, copy the sorted elements back to X
    std::copy(S.begin(), S.end(), X.begin());
}

bool isPositiveNumeric (std::string const& s) {

	return (s.find_first_not_of ("0123456789") == std::string::npos);
}

int main(int ac, char **av) {

    std::vector<int> arr = {3, 5, 2, 4, 9, 8, 7, 1, 6};
    
	for (int i = 1; i < ac; ++i)
	{
		if (!isPositiveNumeric (av [i]))
			std::cerr << "Invalid input. Only positive integers are allowed." << std::endl;

		long long num = std::atoll (av [i]);
		if (num == 0 || num > std::numeric_limits <int>::max ())
			throw PmergeMe::Error ("Invalid input. Only positive integers are allowed.");

		int elem = static_cast <int> (num);
		_vecContainer.push_back (elem);
		_listContainer.push_back (elem);
	}
    fordJohnsonSort(arr);
    
    // Print sorted array
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

