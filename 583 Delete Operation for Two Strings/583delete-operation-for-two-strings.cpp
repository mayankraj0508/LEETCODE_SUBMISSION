class Solution {
public:
vector<vector<int>>dp;
    int f(int i ,int j,string &a,string &b){
        if (i < 0) return j + 1; 
        if (j < 0) return i + 1;  
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else if(i>=0&&j>=0&&a[i]==b[j]){
            return dp[i][j] =  f(i-1,j-1,a,b);
        }
        else{
            return dp[i][j] =  min(1+f(i-1,j,a,b),1+f(i,j-1,a,b));
        }
    }
    int minDistance(string word1, string word2) {
        dp.assign(505,vector<int>(505,-1));
        return f(word1.size()-1,word2.size()-1,word1,word2);
        
    }
};