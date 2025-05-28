class Solution {
public:
    vector<vector<int>> generate(int numrows) {
        vector<vector<int>>ans;
        vector<int>ans1;
        int val = 1;
        for(int i =0;i<numrows;i++){
            for(int j = 0; j<=i; j++){
                ans1.push_back(val);
                val = val*(i-j)/(j+1);
            }
            ans.push_back(ans1);
            int l  = ans.size();
            for(int k = 0; k<l;k++){
                ans1.pop_back();
               
            }
           val = 1;
        }
        return ans;
    }
};