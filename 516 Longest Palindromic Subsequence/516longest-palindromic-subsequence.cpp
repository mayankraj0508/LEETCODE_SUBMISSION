class Solution {
public:
vector<vector<int>>dp;
int f(int i,int j,string &s){
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
      }
    if(s[i]==s[j]){
        return dp[i][j] =  2+f(i+1,j-1,s);
    }
    else{
        return dp[i][j] = max(f(i+1,j,s),f(i,j-1,s));

    }
}

    int longestPalindromeSubseq(string s) {
        //other method will be reverse the str9inmg and make thjis reversed this string as second string and given string as first string and use same algo as done for finding lkongest common subsequence of two string as reversed string and original str8ing have same common palindromic subsequence 
        dp.assign(1005,vector<int>(1005,-1));
        return f(0,s.size()-1,s);
        
    }
};