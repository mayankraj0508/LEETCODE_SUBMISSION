class Solution {
public:
    int findKthPositive(vector<int>&nums, int k) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid  = lo+(hi-lo)/2;
            int gap = nums[mid]-mid-1;
            if(gap<k){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }

        }
        // if(nums.size()==1){
        //     if(nums[0]==1){
        //         return 1+k;
        //     }
        //     else{
        //        return  k;
        //     }
        // }
      return lo+k;
        
    }
};