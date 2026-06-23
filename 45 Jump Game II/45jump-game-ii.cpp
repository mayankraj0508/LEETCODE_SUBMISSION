class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int i =0;
        int count  = 0;
        while( i<nums.size()-1){
            count++;
            int x =  nums[i];
            int mx = INT_MIN;
            int indu   = -1;
            for(int j =0; j<=nums[i]; j++){
                int id = i+j;
                if(id>=nums.size()-1){
                    return count;
                }
                if(nums[id]+id>=mx){
                    mx = nums[id]+id;
                    indu = id;
                }
            }
            i = indu;
        }
      return count;
        
    }
};