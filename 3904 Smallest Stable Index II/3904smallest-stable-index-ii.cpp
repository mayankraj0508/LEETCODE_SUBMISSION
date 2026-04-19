class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> Min(n);
        Min[n-1] = nums[n-1];
        
        for(int i = n-2; i >= 0; i--) {
            Min[i] = min(nums[i], Min[i+1]);
        }
        
        int prefixMax = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            
            if(prefixMax - Min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};