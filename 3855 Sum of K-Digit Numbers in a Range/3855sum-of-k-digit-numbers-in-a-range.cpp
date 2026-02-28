class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int sumOfNumbers(int l, int r, int k) {
        
        long long cnt = r - l + 1;  // number of digit choices
        
        // Sum of digits from l to r
        long long digitSum = (cnt * (l + r)) % MOD;
        digitSum = (digitSum * modPow(2, MOD - 2)) % MOD;  // divide by 2
        
        // cnt^(k-1)
        long long cntPow = modPow(cnt, k - 1);
        
        // Geometric sum: (10^k - 1) / 9
        long long tenPow = modPow(10, k);
        long long geo = (tenPow - 1 + MOD) % MOD;
        geo = (geo * modPow(9, MOD - 2)) % MOD;  // divide by 9
        
        long long ans = digitSum;
        ans = (ans * cntPow) % MOD;
        ans = (ans * geo) % MOD;
        
        return (int)ans;
    }
};