class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n  = mat[0].size();
        int ans = 0;
        int final_ans =0;
        for(int i =0; i<m;i++){
            int count = 0;
            for(int j =0; j<n; j++){
              if(mat[i][j]==1){
                count++;
              }
            }
            if(count>ans){
                ans = count;
                final_ans = i;
            }
        }
        return {final_ans,ans};

    }
};