//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int f(int x, int A, int B, int C) {
        return A*x*x + B*x + C;
    }
    
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        
        int n = arr.size();
        vector<int> result(n);
        int i=0, j=n-1;
        
        int index = (A>=0) ? n-1: 0;
        
        while(i <= j) {
            int val_i = f(arr[i], A, B, C);
            int val_j = f(arr[j], A, B, C);
            
            if(A >= 0) {
                if(val_i > val_j) {
                    result[index--] = val_i;
                    i++;
                } else {
                    result[index--] = val_j;
                    j--;
                }
            } else {
                if (val_i < val_j) {
                    result[index++] = val_i;
                    i++;
                } else {
                    result[index++] = val_j;
                    j--;
                }
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
