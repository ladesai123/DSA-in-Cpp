/*
 * Problem: Maximum Circular Subarray Sum
 * Difficulty: Hard
 * Description:
 *   Given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray.
 *   A subarray can be a normal segment or a circular wraparound (starting at end, wrapping to beginning).
 *
 * Approach:
 *   - Use Kadane's algorithm to find the maximum subarray sum (non-wrapping case).
 *   - Also use a variation of Kadane’s to find the minimum subarray sum.
 *   - Compute the total sum of the array.
 *   - The maximum circular sum will be:
 *         max(normal_max_sum, total_sum - min_subarray_sum)
 *   - Special case: if all elements are negative, we return the normal Kadane result (wrapping sum will be 0 or invalid).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Author: Lade Sai Teja
 * GitHub: https://github.com/<ladesai123>
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int totalSum = 0;

        // Variables to track max and min subarray sums
        int maxKadane = INT_MIN, currMax = 0;
        int minKadane = INT_MAX, currMin = 0;

        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            totalSum += val;

            // Standard Kadane’s for max subarray sum
            currMax = max(val, currMax + val);
            maxKadane = max(maxKadane, currMax);

            // Modified Kadane’s for min subarray sum
            currMin = min(val, currMin + val);
            minKadane = min(minKadane, currMin);
        }

        // Handle edge case: all elements are negative
        if (maxKadane < 0)
            return maxKadane;

        // Return the maximum of non-wrapping and wrapping cases
        return max(maxKadane, totalSum - minKadane);
    }
};

// Driver code (for testing)
int main() {
    Solution sol;
    
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    cout << "Max Circular Sum: " << sol.maxCircularSum(arr1) << endl; // Expected: 22

    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Max Circular Sum: " << sol.maxCircularSum(arr2) << endl; // Expected: 23

    vector<int> arr3 = {5, -2, 3, 4};
    cout << "Max Circular Sum: " << sol.maxCircularSum(arr3) << endl; // Expected: 12

    vector<int> arr4 = {-5, -3, -2};
    cout << "Max Circular Sum: " << sol.maxCircularSum(arr4) << endl; // Expected: -2

    return 0;
}
