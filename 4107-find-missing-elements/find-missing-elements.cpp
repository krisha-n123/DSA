class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size() , i = 0;
        while (n--) {
            if (nums[i] < mini) {
                mini = nums[i];
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
            i++;
        }
        set<int> s(nums.begin(), nums.end());
        vector<int> v;
        while (mini <= maxi) {
            if (s.find(mini) == s.end()) {
                v.push_back(mini);
            }
            mini++;
        }
        return v;
    }
};