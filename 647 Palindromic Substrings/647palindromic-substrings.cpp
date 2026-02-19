class Solution {
public:
    vector<vector<int>>dp;
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        dp.resize(n,vector<int>(n,1));
        for(int i =n-1; i>=0; i--){
            for(int j =i; j<n; j++){
                if(i>j){
                    dp[i][j] = 0;
                }
                else if(j-i==0 || j-i==1 || j-i==2){
                    if(s[i]==s[j]){
                        dp[i][j] = 1;
                        count++;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                   if(dp[i+1][j-1]==1 && s[i]==s[j]){
                      dp[i][j] = 1;
                      count++;
                   }
                   else{
                    dp[i][j] = 0;
                   }
                }
            }
        }
        return  count;
        
    }
};