class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int one = 0;
        string ans = "";

        for(int right = 0; right < n; right++) {
            if(s[right] == '1')
                one++;

            while(one > k) {
                if(s[left] == '1')
                    one--;
                left++;
            }

            while(one == k && s[left] == '0')
                left++;

            if(one == k) {
                string curr = s.substr(left, right-left+1);

                if(ans == "" || curr.size() < ans.size() ||
                   (curr.size() == ans.size() && curr < ans))
                    ans = curr;
            }
        }

        return ans;
    }
};