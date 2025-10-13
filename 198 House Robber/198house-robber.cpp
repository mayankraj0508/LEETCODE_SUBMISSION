class Solution {
public:
    vector<int>dp;
    int ftd(vector<int>&arr,int i){
        int n = arr.size();
             if(i==n-1){
            return arr[n-1];
            
        }
        if(i==n-2){
            return max(arr[n-1],arr[n-2]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(arr[i]+ftd(arr,i+2),ftd(arr,i+1));
    }
    int f(vector<int>& arr, int i,int profit) {
        int n = arr.size();
        if(i==n-1){
            return profit + arr[i];
        }
        if(i==n-2){
            return max(profit+arr[i],profit+arr[i+1]);
        }
        return max(f(arr,i+2,profit+arr[i]),f(arr,i+1,profit));
        
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
      //  int profit= 0;
       int i =0;
      // return  f(nums,i,profit);
        return ftd(nums,i);

    }
};