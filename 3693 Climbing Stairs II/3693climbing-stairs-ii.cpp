class Solution {
public:    
   vector<int>dp;
   vector<int>cp;
   int fbu(int i,vector<int>&cost,int n){
    for(int i =n-2; i>=0;i--){
        if(i==n-2){
            cp[i] = min(cost[i]+1+cp[i+1],cost[i+1]+4+cp[i+2]);
        }
        else{
        cp[i] = min({cost[i]+1+cp[i+1],cost[i+1]+4+cp[i+2],cost[i+2]+9+cp[i+3]});
        }
    }
    return cp[0];

    
   }
    int f(int i,vector<int>&costs,int n){
        int ans;
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
       else if(i==n-1){
            ans = costs[n-1]+1;
        }
        else if(i==n-2){
            ans = min(costs[i]+1+f(i+1,costs,n),costs[i+1]+4+f(i+2,costs,n));

        }
       else{
         ans = min({costs[i]+1+f(i+1,costs,n),costs[i+1]+4+f(i+2,costs,n),costs[i+2]+9+f(i+3,costs,n)});
       }
        return dp[i] =ans;
    }
     int climbStairs(int n, vector<int>& costs) {
        dp.clear();
        dp.resize(n+1,-1);
        cp.resize(n+1);
        cp[n] = 0;
        cp[n-1] = costs[n-1]+1;
     return fbu(0,costs,n);
        

    }
};