class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int req_count = floor(n/3);

        int cnd1 = -1; 
        int count1 = 0;

        int cnd2 = -1; 
        int count2 = 0;



        for(int num: nums){
            if(count1 == 0 && num != cnd2) {
                cnd1 = num;
                count1++;
            } else if(count2==0 && num != cnd1) {
                cnd2 = num;
                count2++;
            }else if(cnd1 == num) {
                count1++;
            } else if(cnd2 == num) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0; 
        count2 = 0;
        for(int num : nums) {
            if(num == cnd1) {
                count1++;
            } else if(num == cnd2) {
                count2++;
            }

        }

        if(count1 > req_count && count2 > req_count) {
            return {cnd1, cnd2};
        } else if(count1 > req_count) {
            return {cnd1};
        } else if(count2 > req_count) {
            return {cnd2};
        } else {
            return {};
        }

    }
};
