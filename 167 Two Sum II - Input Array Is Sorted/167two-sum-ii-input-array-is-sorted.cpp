class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0; 
        int j =nums.size()-1;
        int sum = 0;
        while(i<=j){
            sum = nums[i]+nums[j];
            if(sum==target){
                return {i+1,j+1};
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {i,j};
        
    }
};