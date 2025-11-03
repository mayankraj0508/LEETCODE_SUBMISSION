class Solution {
public:
    bool ispeak(vector<int>&nums,int idx){
        if(idx==0){
            return nums[idx]>nums[idx+1];
        }
        if(idx==nums.size()-1){
            return nums[idx]>nums[idx-1];
        }
        return (nums[idx]>nums[idx+1])&&(nums[idx]>nums[idx-1]);
    }
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi   = nums.size()-1;
        if(nums.size()==1){
            return 0;

        }
        if(nums.size()==2){
            if(nums[0]>nums[1]){
                return 0;
            }
            return 1;
        }
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(ispeak(nums,mid)){
                return mid;
            }
            if(mid==0){
            if(nums[0]>nums[1]){
                return 0;
            }
            return 1;
        }
            else if(nums[mid]>nums[mid+1]||nums[mid-1]>nums[mid]){
                hi = mid-1;
            }
            else if(nums[mid]>nums[mid-1]||nums[mid]<nums[mid+1]){
                lo = mid+1;
            }
        }
        return -1;

        
    }
};