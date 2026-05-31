class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        unordered_map<int,int>m;
        while(n>0){
            int x = n%10;
            m[x]++;
            n = n/10;
        }
        for(auto x:m){
            ans = ans+ x.first*x.second;
        }
        return ans;
        
    }
};