class Solution {
public:
vector<int>dp;
    int f(int n){
        if(n==0){
            return 1;
        }
        if(n==1||n==2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       
        int sum =0;
        for(int k=1; k<=n; k++){
            sum =  sum+f(k-1)*f(n-k);

        }
        return dp[n]= sum;
    }
    int numTrees(int n) {
        dp.resize(20,-1
        );
       return f(n);
        
    }
};