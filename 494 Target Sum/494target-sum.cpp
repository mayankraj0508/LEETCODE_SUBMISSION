class Solution {
public:
   vector<vector<int>>dp;
   int offset ;
    int f(vector<int>&nums,int i,int sum,int target){
        if(i>=nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+offset]!=-1){
            return dp[i][sum+offset];
        }
       return dp[i][sum+offset] =f(nums,i+1,sum+nums[i],target)+f(nums,i+1,sum-nums[i],target);
       

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size()+1,vector<int>(2004,-1));
        int sum = 0;
        for(int i =0; i<nums.size(); i++){
            sum = sum+nums[i];
        }
        offset  =sum;
        return f(nums,1,-nums[0],target)+f(nums,1,nums[0],target);
     
    
        
    }
};