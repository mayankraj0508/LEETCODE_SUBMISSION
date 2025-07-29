class Solution {
public:
    vector<vector<int>>dp;
    int f(vector<int>&prices,int i,bool on,int fee){
        if(i>=prices.size()){
            return 0;
        }
        int idx = (int)on;
        if(dp[i][idx]!=-1){
            return dp[i][idx];
        }
        int a = f(prices,i+1,on,fee);
        int b = INT_MIN;
        int c = INT_MIN;
        if(on==false){
            b = f(prices,i+1,true,fee)-prices[i];
        }
        else if(on==true){
            c = f(prices,i+1,false,fee)+prices[i]-fee;
        }
        return dp[i][idx]=max(a,max(b,c));

    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(100000,vector<int>(2,-1));
        return f(prices,0,false,fee);

        
    }
};