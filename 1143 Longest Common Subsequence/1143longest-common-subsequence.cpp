class Solution {
public:
vector<vector<int>>dp;
    int f(int i,int j, string &a,string &b){
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return dp[i][j]=1+f(i-1,j-1,a,b);
        }
        else{
            return dp[i][j] = max(f(i-1,j,a,b),f(i,j-1,a,b));

        }


    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(1005,vector<int>(1005,-1));
        return f(text1.size()-1,text2.size()-1,text1,text2);
        
    }
};