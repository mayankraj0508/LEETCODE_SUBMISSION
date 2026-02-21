class Solution {
public:
    vector<vector<int>>dp;

    int f(int i ,int prev,vector<int>&nums){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int len = 0+f(i+1,prev,nums);

        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+f(i+1,i,nums));
        }
        return dp[i][prev+1]=len;
          
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,0));
        for(int i =n-1; i>=0; i--){
            for(int j = i-1; j>=-1; j--){
          int len = 0+dp[i+1][j+1];

        if(j==-1 || nums[i]>nums[j]){
            len = max(len,1+dp[i+1][i+1]);
        }
        dp[i][j+1] = len;
            }
        }
        return dp[0][0];   
    }
};