class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        
        unordered_set<int> st;
        int res=0;
        for(int a:arr){
            st.insert(a);
        }
        for(int a:arr){
            if(st.find(a)!=st.end()&&st.find(a-1)==st.end()){
                int curr=a;
                int count=0;
               while(st.find(curr)!=st.end()){
                   count++;
                   st.erase(curr);
                   curr++;
               } 
               res=max(res,count);
            }
        }
        return res;
    }
};
