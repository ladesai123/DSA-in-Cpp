class Solution {
  public:
    vector<int> multiply(int n,vector<int> digits){
        long int carry=0;
        for(int i=0;i<digits.size();i++){
            int result=digits[i]*n+carry;
            digits[i]=result%10;
            carry=result/10;
            
        }
        while(carry){
            digits.push_back(carry%10);
            carry=carry/10;
            
        }
        return digits;
    }
    vector<int> factorialSaiTeja(int n) {
        if(n<=2){
            return multiply(n,{1});
        }
        return multiply(n,factorialSaiTeja(n-1));
    }
    vector<int> factorial(int n) {
        vector<int> ans=factorialSaiTeja(n);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
