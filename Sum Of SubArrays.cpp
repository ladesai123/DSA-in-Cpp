/**
 * Problem: Sum of Subarrays
 * ----------------------------------
 * Given an array 'arr', find the sum of all subarrays.
 * 
 * Each element arr[i] contributes to several subarrays.
 * The number of subarrays in which arr[i] appears is:
 *     (i + 1) * (n - i)
 * 
 * So the total contribution of arr[i] is:
 *     arr[i] * (i + 1) * (n - i)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            // arr[i] contributes to (i + 1) * (n - i) subarrays
            totalSum += arr[i] * (i + 1) * (n - i);
        }

        return totalSum;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};

    cout << "Sum of all subarrays: " << sol.subarraySum(arr) << endl;
    return 0;
}



//Python3 code
/*
class Solution:
    def subarraySum(self, arr):
        # code here 
        n = len(arr)
        sum = 0
        for i in range(n):
            sum += arr[i]*(n-i)*(i+1)
            
        return sum
*/
