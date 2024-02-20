class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0; 
        int hi = nums.size()-1; 
        int mid = (lo + hi)/2;
       
      /*  while(nums[mid]>target){
            lo++;
            hi = mid-1;
            mid = (lo + hi)/2;
        
        }//*/
      /*  if(nums[mid]>target){
            hi = mid-1; 
            mid = (lo+hi)/2;

        }
        else if (nums[mid]<target){
            lo = mid +1;
            mid =  (lo + hi)/2;

        }
        else{
            return mid;
        }*/
        while(lo<= hi){
            int mid =  (lo+hi)/2;
            if(nums[mid]>target){
                hi = mid - 1;

            } 
            else if(nums[mid]<target){
                lo = mid + 1;
            } 
            else{
                return mid;
            }

        }
        return -1;
     
        
    }
};