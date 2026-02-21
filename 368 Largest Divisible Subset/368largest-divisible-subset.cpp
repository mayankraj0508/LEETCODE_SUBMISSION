class Solution {
public:
   // vector<int>ans;
    unordered_map<int,int>m;
    vector<int>dp;
    int mxsize = 0;
    void f(vector<int>&nums, vector<int>&v,int i ){
        

        
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       // sort(nums.begin(), nums.end());
      //  vector<int>v;
        int maxi = 0;
        int lastidx = 0;
        int n = nums.size();
        dp.resize(n,1);
        sort(nums.begin(),nums.end());
        for(int i =0; i<n; i++){
            m[i]=i;
            for(int j =0; j<i; j++){
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0){
                    if(dp[i]<=1+dp[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                    m[i] = j;
                    }
                }
            }
            if(dp[i]>maxi){
                maxi= dp[i];
                lastidx = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastidx]);
        while(m[lastidx]!=lastidx){
            lastidx = m[lastidx];
            ans.push_back(nums[lastidx]);
        
    }
    return ans;
    }
};