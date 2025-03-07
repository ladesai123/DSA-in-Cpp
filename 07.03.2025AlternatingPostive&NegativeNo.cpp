//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> pos, neg;
        
        for(int i=0; i<n; i++) {
            if(arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }
        if(pos.size() > neg.size()) {
            for(int i =0; i< neg.size(); i++) {
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
            int index = neg.size() * 2;
            for(int i=neg.size(); i<pos.size(); i++) {
                arr[index] = pos[i];
                index++;
            }
        } else {
            for(int i =0; i< pos.size(); i++) {
                arr[2*i] = pos[i];
                arr[2*i+1] = neg[i];
            }
            int index = pos.size() * 2;
            for(int i=pos.size(); i<neg.size(); i++) {
                arr[index] = neg[i];
                index++;
            }
        }
        
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
