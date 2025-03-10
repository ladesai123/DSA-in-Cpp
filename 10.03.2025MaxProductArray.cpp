class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
    
        int prefix=1;
        int suffix=1;
        int ans=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix*=arr[i];
            suffix*=arr[n-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;
    }
};
