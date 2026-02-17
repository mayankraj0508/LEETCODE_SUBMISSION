class Solution {
public:
  int last ;
  int n;
  vector<vector<int>>dp;
  unordered_map<int,int>m;
  unordered_set<int>s;
    bool f(int k,int mov){
        if(s.find(k)==s.end()){
            return false;
        }
        if( mov>=n || mov<=0){
            return false;
        }
        if(dp[m[k]][mov]!=-1){
            return dp[m[k]][mov];
        }
        if(k==last){
            return true;
        }
       
        if(mov==1){
            return dp[m[k]][mov] = f(k+1,1)||f(k+2,2);
        }
        else{
           return dp[m[k]][mov]=f(k+mov-1,mov-1)||f(k+mov+1,mov+1)||f(k+mov,mov);
        }
  
    }
    bool canCross(vector<int>& stones) {
        n =stones.size();
         last = stones[stones.size()-1];
        dp.resize(n+1,vector<int>(n+1,-1));
        for(int i =0; i<n; i++){
          m[stones[i]]=i;
          s.insert(stones[i]);
        }
        if(stones[1]!=1){
            return false;

        }
       
        bool ans  = f(1,1);
        return ans;
        
    }
};