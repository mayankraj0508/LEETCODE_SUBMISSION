class Solution {
public:
    bool f(vector<vector<int>>&nums ,int i, int j){
         
            int num = nums[i][j];
            int r = i;
            int c= j;
            while(r>=0 && r<nums.size() && c>=0 && c<nums[0].size()){
                if(nums[r][c]!=num){
                  return false;
                }
                r++;
                c++;
            }
         
         return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int row = 0;
        int col = 0;
        bool ans ;
        for(int j = col; j<n; j++){
            ans = f(nums,row,j);
            if(ans==false){
                return false;
            }
        }
       for(int i = 0; i<m; i++) {
          ans = f(nums,i,col);
          if(ans==false){
            return false;
          }
       }
       return true;
        
    }
};