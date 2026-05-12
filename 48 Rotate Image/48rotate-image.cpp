class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int  n  = nums.size();
        for(int i = 0; i<n; i++){
            for(int j=0; j<i;j++){
                if(i!=j){
                swap(nums[i][j],nums[j][i]);
                }
            }
        }
        for(int k =0; k<n;k++){
            int i =0;
            int j = n-1;
            while(i<j){
                swap(nums[k][i],nums[k][j]);
                i++;
                j--;
            }

        }
        
        
    }
};