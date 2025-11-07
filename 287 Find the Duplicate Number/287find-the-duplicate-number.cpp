class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
           int idx = nums[i];
           int id = abs(idx);
           if(nums[id]<0){
            return id;
           }
           else {
            nums[id] = -nums[id];
           }
        }
        return -1;
        
    }
};