class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int allzero=1;
        for (int i = 0; i < nums.size(); i++) {
            
            ans=ans^nums[i];
            if(nums[i]) allzero=0;

        }
        if(allzero) return 0;
        if(ans!=0) return nums.size();

        return nums.size()-1;
    }
};