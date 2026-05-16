class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i =0 ;
        int j = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int>ans;
        while(i>=0 && i<m && j<n && j>=0){
            //up 
            while(i>=0 && i<m && j<n && j>=0){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(j>=n){
            j = n-1;
            i = i+2;

            }
            else{
            i++;
            }
            //down 
            while(i>=0 && i<m && j<n && j>=0 ){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(i>=m){
                i = m-1;
                j = j+2;
            }
            else{
                j++;
            }
          

        }
        return ans;


    }
};