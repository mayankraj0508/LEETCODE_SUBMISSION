class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int mid = lo +(hi-lo)/2;
        while(lo<hi&& mid>=1){
            int mid = lo + (hi-lo)/2;
            if(mid==0){
                break;
            }
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid+1]==nums[mid]){
                if(mid%2==0){
                    lo = mid+1;
                }
                else{
                    hi = mid;
                }
            }
            else{
                 if(mid%2!=0){
                    lo = mid+1;
                }
                else{
                    hi = mid;
                }

            }
          
           
     
        }
        return nums[lo];
        
    }
};