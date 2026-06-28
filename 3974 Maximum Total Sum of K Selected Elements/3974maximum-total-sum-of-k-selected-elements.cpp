class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int i =nums.size()-1;
        long long ans  = 0;
        while(k--){
            if(mul>0){
                ans  =  ans + (long long)nums[i]*mul;
                mul--;
            }
            else{
                ans   = ans +  nums[i];
            }
            i--;
        }
        return ans ;
        
    }
};