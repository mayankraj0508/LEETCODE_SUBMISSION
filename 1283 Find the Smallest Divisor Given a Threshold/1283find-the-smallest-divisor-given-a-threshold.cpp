class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = INT_MIN;
        for(int i =0;i<nums.size(); i++){
            hi = max(hi,nums[i]);
        }
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            int p = 0;
            for(int i =0; i<nums.size(); i++){
                if(nums[i]%mid==0){
                    p = p + nums[i]/mid;
                }
                else{
                    p = p + (nums[i]/mid)+1;
                }
            }
            if(p<=threshold){
                ans= min(mid,ans);
                hi = mid-1;
            }
            else if(p>threshold){
                lo = mid+1;

            }
           
            
            
            
       }
       return ans;
        
    }
};