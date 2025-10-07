class Solution {
public:
    int ans;
    
    vector<vector<int>>dp;
    int f(vector<int>&nums,int i,int mark){
        if(i==nums.size()-1){
            if(mark==0){
                return nums[nums.size()-1];
            }
            else{
                return 0;
            }
        }
        if(i==nums.size()-2){
            int cal = max(nums[nums.size()-1],nums[nums.size()-2]);
            if(cal==nums[nums.size()-1]){
                if(mark==0){
                    return nums[nums.size()-1];
                }
                else{
                    return nums[nums.size()-2];
                }
            }
            else{
                return nums[nums.size()-2];
            }
        }
        if(dp[i][mark]!=-1){
            return dp[i][mark];
        }
        if(i==0){
            ans   = max(f(nums,i+1,0),nums[i]+f(nums,i+2,1));
        }
        else{
            if(mark==1){
                     ans = max(f(nums,i+1,1),nums[i]+f(nums,i+2,1));
            }
            else{
         ans = max(f(nums,i+1,0),nums[i]+f(nums,i+2,0));
            }
        }
         return dp[i][mark]=ans;
    }
    int rob(vector<int>& nums) {
        dp.resize(105,vector<int>(2,-1));
        return f(nums,0,0);
        
    }
};