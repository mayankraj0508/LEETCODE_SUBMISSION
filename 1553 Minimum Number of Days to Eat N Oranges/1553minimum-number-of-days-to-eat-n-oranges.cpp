class Solution {
public:
vector<int>dp;
unordered_map<int,int>m;
int compare(int a,int b,int c){
    int mn = min(a,b);
    int kn = min(mn,c);
    return kn;
}
int ans(int n){
    if(n<=0){
        return n;
    }
    
    if(n==1){
        return 1;
    }
    if(m.find(n)!=m.end()){
        return m[n];
    }
   // int a ;
   // a = 1+ans(n-1);
    int b = INT_MAX;
    
     b =1+ans(n/2)+n%2;
    
 
    int c = INT_MAX;
   
     c = 1+ans(n/3)+n%3;
    
   
    return m[n]=min(b,c);
}
    int minDays(int n) {
        
      //  dp.resize(n+1,-1);
      
        return ans(n);
        
    }
};