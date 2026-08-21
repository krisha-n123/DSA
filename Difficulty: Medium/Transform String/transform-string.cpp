class Solution {
public:
    int transform(string s1, string s2) {
        if (s1.length() != s2.length())
            return -1;
        vector<int> freq(256, 0);

        for (char c : s1)
            freq[c]++;

        for (char c : s2)
            freq[c]--;

        for (int x : freq) {
            if (x != 0)
                return -1;
        }

        int i = s1.length() - 1;
        int j = s2.length() - 1;

        int ans = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                ans++;
                i--;
            }
        }

        return ans;
    }
};