class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int sr = 0;
        int sc = n-1;
      
        while(sr<m && sc<n && sr>=0 && sc>=0){
        int num = mat[sr][sc];
        if(num==target){
            return true;
        }
        else if(num>target){
            sc--;
        }
        else{
            sr++;
        }
            
        }
        return false;

        
    }
};