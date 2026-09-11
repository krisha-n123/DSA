class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> s;
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (digits[i] == 0)
                        continue;
                    if (i == j || j == k || i == k) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k] * 1;
                    if (num % 2 == 0) {
                        if (s.count(num)) {
                            continue;
                        } else {
                            s.insert(num);
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};