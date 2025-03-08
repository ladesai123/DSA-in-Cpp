class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        
        int sum = 0;
        
        unordered_set<int> seenSums;
        
        for(int i=0; i<n; i++) {
            sum += arr[i];
            
            if(sum == 0 || seenSums.find(sum) != seenSums.end()) {
                return true;
            }
            //the above line can be written as 
            //if(sum == 0 || seenSums.count(sum) > 0) return true;//if
            
            seenSums.insert(sum);
        }
        
        return false;
        
    }
};
