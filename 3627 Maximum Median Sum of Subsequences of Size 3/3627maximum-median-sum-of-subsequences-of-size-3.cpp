class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0; 
        int j = nums.size()-2;
        int k = nums.size()-1;
        long long ans = 0;
        int it = 0;
        int limit = nums.size()/3;
        while(it<limit ){
            ans = ans+nums[j];
            i++;
            k = j-1;
            j = k-1;
            it++;
        }
        return ans;
    }
};