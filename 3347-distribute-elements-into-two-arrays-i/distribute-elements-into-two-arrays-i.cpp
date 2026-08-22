class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int a = 0, b = 1;

        int i = 2, n = nums.size();

        while (i < n) {
            if (nums[a] > nums[b]) {
                int temp = nums[i];
                for (int j = i; j > a + 1; j--) {
                    nums[j] = nums[j - 1];
                }
                nums[a+1] = temp;a++;
                b++;
            } else {
                b++;
            }
            i++;
        }
        return nums;
    }
};