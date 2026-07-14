class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
         int n = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            n = (n + arr[i] + 1) / 2;
        }

        return n;
    }
};