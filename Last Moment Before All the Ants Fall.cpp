// Problem: Last Moment Before All Ants Fall Out
// Source: GeeksforGeeks
// Difficulty: Medium

/*
Problem Description:
--------------------
Given a wooden plank of length 'n' units, ants are walking on it. Some ants move left and others right.
Each ant moves at 1 unit/second. If two ants meet, they change direction instantly.

However, since ants are indistinguishable, direction change on collision doesn’t affect the outcome. 
Effectively, we can think they just pass through each other.

Goal: Find the time when the last ant falls off the plank.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;

        // Ants moving left will fall off in `left[i]` seconds (distance from 0)
        for (int i = 0; i < left.size(); i++) {
            time = max(time, left[i]);
        }

        // Ants moving right will fall off in `n - right[i]` seconds (distance from end)
        for (int i = 0; i < right.size(); i++) {
            time = max(time, n - right[i]);
        }

        return time; // Maximum of both gives last ant fall time
    }
};

/*
Example Usage:

int main() {
    Solution sol;

    int n1 = 4;
    vector<int> left1 = {2};
    vector<int> right1 = {0, 1, 3};
    cout << sol.getLastMoment(n1, left1, right1) << endl; // Output: 4

    int n2 = 4;
    vector<int> left2 = {};
    vector<int> right2 = {0, 1, 2, 3, 4};
    cout << sol.getLastMoment(n2, left2, right2) << endl; // Output: 4

    int n3 = 3;
    vector<int> left3 = {0};
    vector<int> right3 = {3};
    cout << sol.getLastMoment(n3, left3, right3) << endl; // Output: 0

    return 0;
}
*/

/*
Time Complexity: O(L + R)
- Where L = size of left[] array, R = size of right[] array

Space Complexity: O(1)
- Only a constant amount of extra space is used
*/
