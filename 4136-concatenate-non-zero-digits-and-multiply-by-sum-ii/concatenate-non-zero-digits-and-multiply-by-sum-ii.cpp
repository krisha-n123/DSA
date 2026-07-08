class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefVal(n + 1, 0);

        vector<long long> pow10(n + 1), invPow10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        long long inv10 = power(10, MOD - 2);
        invPow10[0] = 1;
        for (int i = 1; i <= n; i++)
            invPow10[i] = invPow10[i - 1] * inv10 % MOD;

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            prefSum[i + 1] = prefSum[i];
            prefVal[i + 1] = prefVal[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                cnt[i + 1]++;
                prefSum[i + 1] += d;
                prefVal[i + 1] = (prefVal[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int total = cnt[r + 1];
            int before = cnt[l];
            int inside = total - before;

            long long left = prefVal[l];
            long long value = (prefVal[r + 1] -
                               left * pow10[inside] % MOD +
                               MOD) % MOD;

            ans.push_back(value * (sum % MOD) % MOD);
        }

        return ans;
    }
};