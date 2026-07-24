class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;
        if (m == 0)
            return s;
    
    long long  k = n/2;
    long long rem   = n%2;
    long long  even  = k;
    long long  odd =  k + rem;
    long long  odd_term  =  s + (odd-1)*(m-1);
    long long even_term  = s + m + +(even-1)*(m-1);
    long  long ans = max(odd_term, even_term);
    return ans;
    
      
    }
};