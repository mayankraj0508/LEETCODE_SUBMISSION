class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int start = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                hi = mid-1;
                start = mid;
            }
            else if(nums[mid]>target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        lo = 0;
        hi = nums.size()-1;
        int end = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                lo = mid+1;
                end = mid;
            }
            else if(nums[mid]>target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return {start,end};

    }
};