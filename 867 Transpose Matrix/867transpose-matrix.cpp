class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans;
        vector<vector<int>>p;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans.push_back(matrix[j][i]);
            }
            p.push_back(ans);
            for(int j = 0; j<m; j++){
                ans.pop_back();
            }
           
        }
        return p;
    }
};