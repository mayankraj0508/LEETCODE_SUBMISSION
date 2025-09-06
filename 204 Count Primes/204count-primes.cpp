class Solution {
public:
    void fillsieve(vector<int>&sieve,int n){
        for(int i = 2; i*i<=n; i++){
            if(sieve[i]==1){
                for(int j =i*i;j<=n; j = j+i){
                    sieve[j] = 0;
                }
            }

        }
    }
    int countPrimes(int n) {
        vector<int>sieve(n+1,1);
        fillsieve(sieve, n);
        int count = 0;
         for(int i =2; i<n; i++){
            if(sieve[i]==1){
                count++;

            }
         }
        return count;  


        
    }
};