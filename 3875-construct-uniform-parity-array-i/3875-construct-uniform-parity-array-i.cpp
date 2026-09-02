class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int n = nums1.size();

        int even = 0;
        int odd = 0;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        if (even == n) {
            return true;
        }

        if (odd == n) {
            return true;
        }
        if (even > 0 && odd > 0) {
            return true;
        }

        return false;
    }
};