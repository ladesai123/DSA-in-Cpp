class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        
        vector<int> res;
        
        int i = 0, j = 0, k = 0;
        
        while(i < n1 && j < n2 && k < n3) {
            
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                
                res.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }else if(arr1[i] < arr2[j]) {
                i++;
            }else if(arr2[j] < arr3[k]) {
                j++;
            }else{
                k++;
            }
        }
        
         // Remove duplicates from result
        res.erase(unique(res.begin(), res.end()), res.end());
        
        if(res.empty()){
            return {-1};
        } 
        
        return res;
        
        
    }
};
