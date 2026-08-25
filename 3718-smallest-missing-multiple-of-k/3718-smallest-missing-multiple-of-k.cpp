class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;
        for(auto it: nums) {
            st.insert(it);
        }
        int mul=1;
        while(true){
            int num=k*mul;
            if(st.find(num)==st.end()) return num;
            mul++;
        }
        return -1;
        
    }
};