class Solution {
public: 
    vector<vector<int>>dp;
    int f(int i,int j,string &s){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]= f(i+1,j-1,s);
        }
        else{
            return dp[i][j] =  min(1+f(i+1,j,s),1+f(i,j-1,s));
        }
    }
    int minInsertions(string s) {\
        dp.assign(505,vector<int>(505,-1));
         return f(0,s.size()-1,s);      
    }
};