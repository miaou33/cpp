#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

// Function for performing binary search
static int binarySearch(const std::vector<int> &S, int start, int end, int key) {
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
static void sortHalf(std::vector<int> &S, const std::vector<int> &X) {
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
    for (int groupSize : groups) {
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
