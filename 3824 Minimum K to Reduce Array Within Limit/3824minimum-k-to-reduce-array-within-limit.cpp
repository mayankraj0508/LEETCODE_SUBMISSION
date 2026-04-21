class Solution {
public:
     long long  find(long long mid,vector<int>&nums){
         long long count = 0;
         for(int i = 0; i<nums.size(); i++){
             if(nums[i]<=mid){
                 count= count+1;
             }
            else if(nums[i]%mid==0){
                 count = count+nums[i]/mid;
             }
             else{
                 count = count+ (nums[i])/(mid) +1;
             }
             
             
         }
         return count;
     }
    int minimumK(vector<int>& nums) {
        int lo = INT_MAX;
        long long  hi = LLONG_MIN;
        
        lo = 1;
        hi = 1e9;
        int ans= INT_MAX;
        while(lo<=hi){
            long long   mid = lo+(hi-lo)/2;
            if(find(mid,nums)<=mid*mid){
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