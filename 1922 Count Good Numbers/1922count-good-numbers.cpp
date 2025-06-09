class Solution {
public:
 const long long MOD = 1e9 + 7;
int pow(long long a, long long b,long long  ans){
    if(b==1||b==0){
        return a;
    }
    long long half = pow(a,b/2,ans);
    ans = half*half;
    if(b%2==1){
        ans = ans*a;
    }

    
      
  
    return (ans)%MOD;

}
    int countGoodNumbers(long long n) {
        long long even_ind;
        long long odd_ind;
        long long t = 1;
        long long ans = 1;
        long long  ans1 =1;
        long long ans2 = 1;
        even_ind = (n+1)/2;
        odd_ind = n/2;
        if(even_ind>0){
        
        ans1 = ans*pow(5,even_ind,t)%MOD;
        }
        if(odd_ind>0){
       ans2 = ans*pow(4,odd_ind,t)%MOD;
        }
        
        return (ans1*ans2)%MOD;
    }
};