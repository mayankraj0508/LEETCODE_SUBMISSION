class Solution {
public:
    const int MOD = 1e9+7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b){
        long long res = 1;
        while(b){
            if(b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void init(int n){
        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0] = 1;
        for(int i = 1; i <= n; i++){
            fact[i] = fact[i-1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD-2);
        for(int i = n-1; i >= 0; i--){
            invFact[i] = invFact[i+1] * (i+1) % MOD;
        }
    }

    long long f(int n, int r, int total){
        if(r < 0 || r > total) return 0;
        return fact[total] * invFact[r] % MOD * invFact[total-r] % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {

        init(n); // added

        long long x = 0; // changed to long long

        for(int i = 0; i <= k; i++){
            int left = i;
            int right = k - i;
            int left_ele = pos;
            int right_ele = n - pos - 1;

            if(k == 0){
                return 2;
            }

            // added VALIDITY CHECK (important)
            if(left > left_ele || right > right_ele) continue;

            if(left_ele < left){
                right = k;
                if(right <= right_ele){
                    x = (x + f(n, k, right_ele)) % MOD;
                }
                else{
                    continue;
                }
            }
            else if(right_ele < right){
                left = k;
                if(left <= left_ele){
                    x = (x + f(n, k, left_ele)) % MOD;
                }
                else{
                    continue;
                }
            }
            else{
                x = (x + 1LL * f(n, left, left_ele) * f(n, right, right_ele) % MOD) % MOD;
            }
        }

        return (x * 2) % MOD; // final multiply
    }
};