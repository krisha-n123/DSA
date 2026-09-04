class Solution {
public:
    int returnmin(vector<int>& nums, int i){
        int mini=*min_element(nums.begin()+i, nums.end());
        return mini;
    }
    int returnmax(vector<int>& nums, int i){
        int mini=*max_element(nums.begin(), nums.begin()+i+1);
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int mini=returnmin(nums, i);
            int maxi=returnmax(nums, i);
            if(maxi-mini <= k && ans==-1){
                ans=i;
            }else if(maxi-mini <= k){
                ans=min(ans,i);
            }
        }
        return ans;
    }
};