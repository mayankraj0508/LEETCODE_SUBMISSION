class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n  = mat[0].size();
        int total = m*n;
        int lo = 0;
        int hi = m*n-1;
        if(m==1 && n==1){
            return mat[0][0]==target;
        }
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int row = mid/n;
            int col = mid%n;
            
          
            if(row<0 || col<0){
                return false;
            }
            if(mat[row][col]<target){
                lo = mid+1;
            }
            else if(mat[row][col]==target){
                return true;
            }
            else{
                hi = mid-1;
            }
        }
        return false;
        
    }
};