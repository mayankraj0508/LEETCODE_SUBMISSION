class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int cntOdd = 0, cntEven = 0;

        for (int x : nums) {
            if (x % 2 == 0) cntEven++;
            else cntOdd++;
        }

        int maxSameParity = max(cntEven, cntOdd);

        // For odd sum pairs, pick alternating parities
        int oddEvenCount = 1;
        for (int i = 1; i < n; ++i) {
            if ((nums[i] + nums[i-1]) % 2 == 1) {
                oddEvenCount++;
            }
        }

        return max(maxSameParity, oddEvenCount);
    }
};
