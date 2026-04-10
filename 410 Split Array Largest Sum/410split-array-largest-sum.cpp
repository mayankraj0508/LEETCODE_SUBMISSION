class Solution {
public:
    int f(vector<int>& nums, int maxSum) {
        int count = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            } else {
                count++;
                sum = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int lo = 0;
        int hi = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            hi = hi+nums[i];
            lo = max(lo,nums[i]);
        }
       int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int calculate = f(nums,mid);
            if(calculate<=k){
                ans = mid;
                hi = mid-1;

            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};