class Solution {
public:
    static const long long MOD = 1000000007;
    static const long long INV2 = 500000004; // inverse of 2 mod MOD

    int minimumCost(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long resource = k;
        long long ans = 0;
        long long x = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (resource < nums[i]) {

                long long need = nums[i] - resource;
                long long freq = (need + k - 1) / k;

                // sum = freq * (2*x + freq - 1) / 2  (mod MOD)
                long long a = freq % MOD;
                long long b = ( (2LL * (x % MOD)) % MOD + (freq - 1) % MOD ) % MOD;

                long long sum = a;
                sum = (__int128)sum * b % MOD;
                sum = (__int128)sum * INV2 % MOD;

                ans = (ans + sum) % MOD;

                resource += freq * 1LL * k;
                x += freq;
            }

            resource -= nums[i];
        }

        return (int)ans;
    }
};