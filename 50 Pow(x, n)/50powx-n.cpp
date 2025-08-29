class Solution {
public:
   double f(double x,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    double half = f(x,n/2);
    if(n%2!=0){
        return half*half*x;
    }
    
    return half*half;

   }
    double myPow(double x, int n) {
      double ans = f(abs(x),(n));
      if(x<0){
        if(n%2!=0){
           ans = -ans;

        }
      }
      if(n<0){
        return 1/ans;
      }
      return ans;
        
    }
};