class Solution {
public: 
   vector<vector<int>>dp;
   int f2(string &s, string &t, int i, int j){
       if(j==t.size()){
        return 1;
       }
       if(i==s.size()){
        return 0;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       int take = 0;
       if(s[i]==t[j]){
          take = f2(s,t,i+1,j+1);
       }
       int leave  = f2(s,t,i+1,j);
       return dp[i][j] = take+leave;

   }
//    int  f(string &s , string ans, string &t, int i){
   
//         // if(i==s.size()){
//         //     if(ans==t){
//         //         return 1;
//         //     }
//         //     else{
                
//         //         return 0;
//         //     }
//         // }
//         if(i>s.size()){
//             return 0;
//         }
          
//         if(i==s.size()){
//             if(ans==t){
//                return dp[i] = 1;
//             }
//             else{
//                 return dp[i]=0;
//             }
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
      
//         if(ans==t){
//             return dp[i]=1;
//         }
//         return  dp[i] = f(s,ans+s[i],t,i+1) +f(s,ans,t,i+1);
        

   // }
    int numDistinct(string s, string t) {
        string ans = "";
        int n =s.size();
         dp.resize(s.size(),vector<int>(t.size(),-1));
         return f2(s,t,0,0);

        
    }
};