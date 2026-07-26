class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPower(long long base, long long exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }

    int countValidSequences(int n, int k) {

      vector<long long >fact(n+1);
        vector<long long> inverse(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        inverse[n] = modPower(fact[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--)
            inverse[i] =
                (inverse[i + 1] * (i + 1)) % MOD;

        auto combination = [&](int N, int R) {

            if (R < 0 || R > N)
                return 0LL;

            return (((fact[N] * inverse[R]) % MOD) *
                    inverse[N - R]) %
                   MOD;
        };

        long long totalSequences = combination(n - 1, k - 1);

        long long Odd = 0;

        if ((n - k) % 2 == 0) {

            int rem = (n - k) / 2;

            Odd =
                combination(rem+ k - 1, k - 1);
        }

        long long answer =
            (totalSequences - Odd + MOD) % MOD;

        return answer;
    }
};