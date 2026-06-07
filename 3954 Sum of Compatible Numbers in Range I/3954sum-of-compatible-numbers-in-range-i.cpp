class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int mn =max(0,n-k);
        int mx = n+k;
        int ans = 0;
        for(int i =mn; i<=mx; i++){
            if(abs(n-i)<=k && !(n&i)){
                ans = ans+i;
            }
        }
        return ans;
        
        
    }
};