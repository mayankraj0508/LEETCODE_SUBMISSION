class Solution {
public:
     vector<vector<int>>dp;
    int f(int i, int j, string & a, string &b ){
        if(i<0 && j<0){
            return 0;
        }
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return dp[i][j] = f(i-1,j-1,a,b);
        }
        else{
            int add = 1+f(i,j-1,a,b);
            int remove = 1+f(i-1,j,a,b);
            int replace  = 1+f(i-1,j-1,a,b);
            return dp[i][j]=min({add,remove,replace});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,word1,word2);
        
    }
};