/*
Problem: ASCII Range Sum

Difficulty: Medium

Given a string `s` consisting of lowercase English letters, 
for every character whose **first and last occurrences** are at different positions, 
calculate the **sum of ASCII values** of characters strictly between its first and last occurrence.

Return all such **non-zero sums**. The order of the output does not matter.

-----------------------------------------------------------
Example 1:
Input:  s = "abacab"
Output: [293, 294]

Explanation:
- 'a' occurs at positions 0, 2, and 4. Characters between 0 and 4 are b, a, c → ASCII sum = 98 + 97 + 99 = 294
- 'b' occurs at positions 1 and 5. Characters between 1 and 5 are a, c, a → ASCII sum = 97 + 99 + 97 = 293

Example 2:
Input:  s = "acdac"
Output: [197, 199]

Explanation:
- 'a' occurs at positions 0 and 3. Between them: c, d → 99 + 100 = 199
- 'c' occurs at positions 1 and 4. Between them: d, a → 100 + 97 = 197

-----------------------------------------------------------
Constraints:
- 1 ≤ s.length ≤ 10^5
- s consists only of lowercase English letters

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) [excluding output vector]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> asciirange(string& s) {
        vector<int> result;

        // For each lowercase letter
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int first = -1, last = -1;

            // Step 1: Find first and last occurrence of 'ch'
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ch) {
                    if (first == -1) first = i;
                    last = i;
                }
            }

            // Step 2: Only proceed if character occurs more than once
            if (first != -1 && first != last) {
                int sum = 0;

                // Step 3: Calculate ASCII sum between first and last occurrence
                for (int i = first + 1; i < last; i++) {
                    sum += s[i];
                }

                // Step 4: Only store non-zero sums
                if (sum > 0) {
                    result.push_back(sum);
                }
            }
        }

        return result;
    }
};

/*
Q: Why do we check only for characters from 'a' to 'z'?
A: Since the input only contains lowercase English letters, we can efficiently loop from 'a' to 'z' (26 letters) 
   and check the first and last occurrence for each.

Q: Why is this approach O(n)?
A: Because we scan the entire string once for each of 26 letters, and each scan is O(n), 
   but the total effective cost remains O(n) due to limited number of characters (constant 26).

-----------------------------------------------------------
Time Complexity:  O(n) — where n is the length of the input string
Space Complexity: O(1) — extra space is constant, result vector is excluded from space complexity
*/

int main() {
    Solution sol;

    string s1 = "abacab";
    vector<int> res1 = sol.asciirange(s1);
    cout << "Output for \"abacab\": ";
    for (int sum : res1) cout << sum << " ";
    cout << endl;

    string s2 = "acdac";
    vector<int> res2 = sol.asciirange(s2);
    cout << "Output for \"acdac\": ";
    for (int sum : res2) cout << sum << " ";
    cout << endl;

    return 0;
}
