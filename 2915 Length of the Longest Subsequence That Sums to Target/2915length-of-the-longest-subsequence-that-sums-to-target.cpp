class Solution {
public:  
    vector<vector<int>>dp;
    int f(int i,int sum,int target,vector<int>&nums){
         if(sum>target){
            return INT_MIN;
        }
        if(i==nums.size()){
            if(sum==target){
                return 0;
            }
            return INT_MIN;
        }
        if(sum==target){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
       
        return dp[i][sum] = max(1+f(i+1,sum+nums[i],target,nums),f(i+1,sum,target,nums));
        
        return 0;
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.resize(1005,vector<int>(1005,-1));
        int ans = f(0,0,target,nums);
        if(ans<0){
            return -1;
        }
        return f(0,0,target,nums);
        
    }
};