class Solution {
public:
    int MOD = 1e9+7;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

   
        vector<long long> power(n);
        power[0] = 1;
        for(int i = 1; i < n; i++){
            power[i] = (power[i-1] * 2) % MOD;
        }

        int lo = 0, hi = n-1;
        long long count = 0;

        while(lo <= hi){
            if(nums[lo] + nums[hi] > target){
                hi--;
            } else {
                count = (count + power[hi - lo]) % MOD;
                lo++;
            }
        }

        return (int)count;
    }
};