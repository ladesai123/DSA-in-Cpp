class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> narsi;
        for(int i=0; i<a.size(); i++) {
            if(narsi[a[i]] == 0) {
                narsi[a[i]] = 1;
            } else {
                narsi[a[i]]++;
            }
        }
        for(int num : b) {
            if(narsi[num] == 0) {
                return false;
            } else {
                narsi[num]--;
            }
        }
        return true;
    }
};
