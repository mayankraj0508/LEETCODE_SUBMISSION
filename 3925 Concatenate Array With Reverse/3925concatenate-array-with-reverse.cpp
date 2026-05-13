class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans(2*nums.size());
        for(int i =0; i<2*nums.size(); i++){
            if(i<=nums.size()-1){
                ans[i]= nums[i];
            }
            else{
                ans[i] = nums[2*nums.size()-i-1];
            }
        }
        return ans;
        
    }
};