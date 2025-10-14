class Solution {
public:
    vector<vector<int>>dp;
    int half;
    bool f(vector<int>&nums,int i,int sum){
        if(i>=nums.size()){
            if(sum==half){
                return true;
            }
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum==half){
            return dp[i][sum] =true;
        }
        if(sum+nums[i]>half){
            return dp[i][sum]  = f(nums,i+1,sum);
        }
        int ans =dp[i][sum]= (f(nums,i+1,sum)||f(nums,i+1,sum+nums[i]));
        if(ans==true){
            return true;
        }
        return ans;
    }
    // bool fbu(vector<int>&nums){
     
    //     for(int i =1; i<nums.size(); i++){
    //        dp[i] = dp[i-1])||(nums[i]+dp[i-1]);
    //        if(dp[i]==half){
    //         return true;
    //        }
    //     }
    //     return dp[nums.size()-1];

    // }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        dp.resize(nums.size()+1,vector<int>(20005,-1));
        for(int i =0; i<nums.size(); i++){
            sum =sum +nums[i];
        }
        if(sum%2!=0){
            return false;
        }
         half = sum/2;
         // dp[0] = 0;
        //  dp[1] = 0;
        bool ans = f(nums,0,0);
        if(ans==true){
            return true;
        }
        return false;
        
    }
};