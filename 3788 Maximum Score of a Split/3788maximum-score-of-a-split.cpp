class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long >prefixsum(nums.size());
        vector<int>suffixmin(nums.size());
        suffixmin[nums.size()-1] = nums[nums.size()-1];
        long long  sum = 0;
        long long  n  = nums.size();
       
        for(int i =0; i<nums.size(); i++){
            sum = sum+nums[i];
            prefixsum[i] = sum;
          
        }
        int mn = INT_MAX;
       
     for(int i = n-2; i >= 0; i--){
        mn= min(nums[i+1],mn);
         suffixmin[i] = mn;
   }
        long long score = LLONG_MIN;
        for(int i =0; i<n-1; i++){
            score = max(score,(long long)prefixsum[i]-suffixmin[i]);
        }

        return score;
        
        
    }
};