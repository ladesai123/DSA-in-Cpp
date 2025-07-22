/*
🔍 Problem: Smallest Positive Missing Number
--------------------------------------------
You are given an integer array `arr[]`. Your task is to find the 
smallest positive number missing from the array.

Note:
- Positive numbers start from 1.
- The array can include negative numbers and zero.

📥 Examples:
-----------
Input:  arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.

Input:  arr[] = [5, 3, 2, 5, 1]
Output: 4

Input:  arr[] = [-8, 0, -1, -4, -3]
Output: 1

📌 Constraints:
--------------
- 1 ≤ arr.size() ≤ 10^5
- -10^6 ≤ arr[i] ≤ 10^6

✅ Approach:
-----------
1. Filter out non-positive numbers (ignore 0 and negatives).
2. Sort the remaining array of positive numbers.
3. Use a variable `missing` starting from 1.
4. Loop through the sorted array:
   - If the current element == `missing`, increment `missing`.
   - If the current element > `missing`, `missing` is the answer.
5. Return `missing`.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        vector<int> positiveArray;

        // Step 1: Filter positive numbers only
        for (int num : arr) {
            if (num > 0) {
                positiveArray.push_back(num);
            }
        }

        // Step 2: Sort the filtered array
        sort(positiveArray.begin(), positiveArray.end());

        // Step 3: Initialize the smallest missing positive number
        int missing = 1;

        // Step 4: Loop to find the smallest missing number
        for (int i : positiveArray) {
            if (i == missing) {
                missing++; // found current missing, check next
            } else if (i > missing) {
                break; // missing number is not present
            }
            // If i < missing (duplicate), skip
        }

        return missing;
    }
};

// 🧪 Sample Testing
int main() {
    Solution sol;

    vector<int> arr1 = {2, -3, 4, 1, 1, 7};
    cout << "Missing number (Test 1): " << sol.missingNumber(arr1) << endl;

    vector<int> arr2 = {5, 3, 2, 5, 1};
    cout << "Missing number (Test 2): " << sol.missingNumber(arr2) << endl;

    vector<int> arr3 = {-8, 0, -1, -4, -3};
    cout << "Missing number (Test 3): " << sol.missingNumber(arr3) << endl;

    return 0;
}
