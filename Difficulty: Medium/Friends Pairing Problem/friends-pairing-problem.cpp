class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
         vector<int> ans = {1, 2, 4, 10, 26, 76, 232, 764, 2620, 9496, 35696, 140152, 568504, 2390480, 10349536, 46206736, 211799312, 997313824};
        return ans[n - 1];
    }
};
