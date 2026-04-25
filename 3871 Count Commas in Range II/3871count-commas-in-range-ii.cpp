class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long start = 1;
        int digits = 1;

        while(start <= n){
            long long end = start * 10 - 1;
            if(end > n) end = n;

            if(digits >= 4){
                int commas = (digits - 1) / 3;
                ans += (end - start + 1) * commas;
            }

            start *= 10;
            digits++;
        }

        return ans;
    }
};