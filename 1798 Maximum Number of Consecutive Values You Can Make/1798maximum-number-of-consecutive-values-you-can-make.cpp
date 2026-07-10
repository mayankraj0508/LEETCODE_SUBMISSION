class Solution {
public:
    int getMaximumConsecutive(vector<int>& nums) {
        int prev = 0;
        int idx = 0;
        int ans  = 0;
        sort(nums.begin(),nums.end());
        int cntones = 0;
        while( idx<nums.size()&&  nums[idx]==1 ){
            cntones++;
            idx++;
        }
        if(idx==nums.size()){
            return cntones+1;
        }
        int i = idx;
        int consecutive = cntones;
        while(i<nums.size()){
            if(nums[i]-consecutive==1){
                consecutive  = consecutive + nums[i];
                i++;
            }
            else if(consecutive>=nums[i]){
                consecutive  = consecutive + nums[i];
                i++;
            }
            else{
                break;
            }
        }
        return consecutive +1 ;
        
    }
};