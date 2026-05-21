class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            int leftidx = i-k;
            int rightidx= i+k;
            if(i-k<0 && i+k>=nums.size()){
                sum = sum+nums[i];
            }
           else if(i-k<0){
                if(nums[i]>nums[i+k])
                sum = sum+nums[i];
            }
           else if(i+k>=nums.size()){
                if(nums[i]>nums[i-k]){
                    sum = sum+nums[i];
                }
            }
            else{
                if(nums[i]>nums[i-k] && nums[i]>nums[i+k]){
                    sum = sum+nums[i];
                }
            }
            
            
        }
        return sum;
    }
};