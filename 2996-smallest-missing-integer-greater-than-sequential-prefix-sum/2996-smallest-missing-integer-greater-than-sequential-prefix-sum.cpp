class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int i=1;
        int presum=0;
        while(i<nums.size() && nums[i]==nums[i-1]+1){
            i++;
        }
        for(int j=0;j<i;j++){
            presum+=nums[j];
        }
        while(s.find(presum)!=s.end()){
            presum+=1;
        }
        return presum;

    }
};