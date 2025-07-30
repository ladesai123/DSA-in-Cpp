/*
    Author: Lade Sai Teja
    Date: July 30, 2025
    Description:
    This program demonstrates two approaches to solve the problem of counting the number of subarrays
    whose sum is equal to a given integer 'k'.

    1. Naive Approach: O(n^2) time complexity using nested loops.
    2. Optimized Approach: O(n) time complexity using prefix sum and a hash map.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ---------------------------------------------
// Naive Approach (Brute Force)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// ---------------------------------------------
int countSubarraysNaive(const vector<int>& arr, int k) {
    int count = 0;

    // Check all subarrays using two nested loops
    for (int start = 0; start < arr.size(); ++start) {
        int sum = 0;
        for (int end = start; end < arr.size(); ++end) {
            sum += arr[end]; // Calculate sum of subarray from start to end
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

// ---------------------------------------------
// Optimized Approach (Prefix Sum + Hash Map)
// Time Complexity: O(n)
// Space Complexity: O(n)
// ---------------------------------------------
int countSubarraysOptimized(const vector<int>& arr, int k) {
    unordered_map<int, int> prefixSums; // Stores frequency of prefix sums
    int currSum = 0; // Running total sum of elements
    int count = 0;   // Number of subarrays with sum = k

    for (int i = 0; i < arr.size(); ++i) {
        currSum += arr[i]; // Update current prefix sum

        // Case 1: If current sum is exactly equal to k
        if (currSum == k) {
            count++;
        }

        // Case 2: Check if there's a prefix sum such that (currSum - prefixSum = k)
        if (prefixSums.find(currSum - k) != prefixSums.end()) {
            count += prefixSums[currSum - k];
        }

        // Update the prefix sum frequency in the map
        prefixSums[currSum]++;
    }

    return count;
}

// ---------------------------------------------
// Main Function
// ---------------------------------------------
int main() {
    vector<int> arr = {10, 2, -2, -20, 10}; // Input array
    int k = -10;                            // Target sum

    // Run both approaches
    int resultNaive = countSubarraysNaive(arr, k);
    int resultOptimized = countSubarraysOptimized(arr, k);

    // Display results
    cout << "Naive Approach Result: " << resultNaive << endl;
    cout << "Optimized Approach Result: " << resultOptimized << endl;

    return 0;
}
