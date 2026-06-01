class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot=-1 ;
        for(int i =n-1; i>=1; i--){
            if(nums[i-1]<nums[i]){
                pivot = i-1;
                break;
            }
        }

        int alpha ;
        int idx;
        if(pivot!=-1){
        for(int i = n-1; i>0; i--){
            if(nums[i]>nums[pivot]){
                alpha = nums[i];
                idx = i;
                break;

            }
        }
        

        swap(nums[pivot],nums[idx]);
        }
        reverse(nums.begin()+pivot+1,nums.end());

        
    }
};