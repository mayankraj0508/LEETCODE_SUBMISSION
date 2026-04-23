class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int ans =INT_MIN;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                sum =0;
            }
            else{
                sum = sum+nums[i];
            }
            ans = max(ans,sum);

        }
        return ans;
        
    }
};