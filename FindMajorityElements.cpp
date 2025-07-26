/*
    Problem: Find all elements in the array that appear more than ⌊ n/3 ⌋ times.

    Approaches Implemented:
    1. Brute-force using Hash Map (Time: O(n), Space: O(n))
    2. Optimized Boyer-Moore Majority Vote Algorithm (Time: O(n), Space: O(1))
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    // 1. Brute-force using Hash Map
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> findMajorityBruteForce(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 3;
        unordered_map<int, int> freq;
        vector<int> result;

        // Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        // Collect elements that appear more than ⌊n/3⌋ times
        for (const auto& pair : freq) {
            if (pair.second > threshold) {
                result.push_back(pair.first);
            }
        }

        sort(result.begin(), result.end()); // For consistent order
        return result;
    }

    // 2. Optimized Boyer-Moore Majority Vote Algorithm
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    vector<int> findMajorityOptimized(vector<int>& arr) {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1;

        // First pass: Find possible candidates
        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: Verify actual counts
        count1 = 0;
        count2 = 0;
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        int threshold = arr.size() / 3;
        vector<int> result;
        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold) result.push_back(candidate2);

        sort(result.begin(), result.end()); // For consistent order
        return result;
    }
};

// Sample driver code
int main() {
    Solution solution;
    vector<int> input = {3, 2, 3};

    // Call both versions
    vector<int> bruteForceResult = solution.findMajorityBruteForce(input);
    vector<int> optimizedResult = solution.findMajorityOptimized(input);

    cout << "Brute-force Result: ";
    for (int x : bruteForceResult) cout << x << " ";
    cout << endl;

    cout << "Optimized Result: ";
    for (int x : optimizedResult) cout << x << " ";
    cout << endl;

    return 0;
}

/*
==============================
🧠 Explanation of Approaches
==============================

1️⃣ Brute-force using Hash Map:
   - We count the frequency of all elements using a hash map.
   - Then, we collect elements that appear more than ⌊n/3⌋ times.

   ✅ Pros:
     - Simple and easy to understand
   ❌ Cons:
     - Uses O(n) extra space for the hash map

2️⃣ Optimized Boyer-Moore Majority Vote Algorithm:
   - Since at most 2 elements can appear more than ⌊n/3⌋ times,
     we track two candidates and their counts in a clever way.
   - First pass to find candidates.
   - Second pass to verify their counts.

   ✅ Pros:
     - Time: O(n), Space: O(1) → very efficient
   ❌ Cons:
     - Slightly tricky to understand at first

===============================
🔍 Time & Space Complexity Recap
===============================

Brute-force:
  - Time: O(n)
  - Space: O(n)

Optimized (Boyer-Moore):
  - Time: O(n)
  - Space: O(1)
*/
