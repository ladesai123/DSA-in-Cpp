/*
Problem: Make Matrix Beautiful
Difficulty: Medium

A beautiful matrix is a square matrix in which the sum of elements 
in every row and every column is equal. 
You can increment any cell by 1 in one operation.

Goal: Find the minimum number of operations required to make 
the matrix beautiful.

Approach:
1. Find the maximum sum among all rows and columns. 
   This will be our target sum for each row and column.
2. For each row, calculate how much it needs to be incremented 
   to match the target sum.
3. Since incrementing cells affects both row and column sums, 
   adjusting rows is enough to balance both (columns will also become equal).

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm> // For max()

using namespace std;

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();        // Matrix is n x n
        int maxsum = 0;            // Target sum for every row/column
        int operations = 0;        // Total number of increments needed

        // Step 1: Find the maximum sum among all rows
        for(int i = 0; i < n; i++) {
            int rowsum = 0;
            for(int j = 0; j < n; j++) {
                rowsum += mat[i][j];
            }
            maxsum = max(maxsum, rowsum); // Keep updating maxsum
        }

        // Step 2: Find the maximum sum among all columns
        for(int j = 0; j < n; j++) {
            int colsum = 0;
            for(int i = 0; i < n; i++) {
                colsum += mat[i][j];
            }
            maxsum = max(maxsum, colsum); // Final target sum
        }

        // Step 3: For each row, calculate how much it needs to be increased
        for(int i = 0; i < n; i++) {
            int rowsum = 0;
            for(int j = 0; j < n; j++) {
                rowsum += mat[i][j];
            }
            // Difference tells how much we need to add to this row
            operations += (maxsum - rowsum);
        }

        return operations;
    }
};

// Optional main function for testing
int main() {
    Solution sol;

    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    cout << "Minimum operations for mat1: " << sol.balanceSums(mat1) << endl;

    vector<vector<int>> mat2 = {{1, 2, 3}, {4, 2, 3}, {3, 2, 1}};
    cout << "Minimum operations for mat2: " << sol.balanceSums(mat2) << endl;

    return 0;
}
