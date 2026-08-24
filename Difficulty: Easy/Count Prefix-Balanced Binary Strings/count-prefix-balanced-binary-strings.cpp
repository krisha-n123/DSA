class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int prefixStrings(int n) {
        vector<long long> fact(2 * n + 1);

        fact[0] = 1;

        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        long long comb = fact[2 * n];

        comb = comb * power(fact[n], MOD - 2) % MOD;
        comb = comb * power(fact[n], MOD - 2) % MOD;

        long long ans = comb * power(n + 1, MOD - 2) % MOD;

        return ans;
    }
};