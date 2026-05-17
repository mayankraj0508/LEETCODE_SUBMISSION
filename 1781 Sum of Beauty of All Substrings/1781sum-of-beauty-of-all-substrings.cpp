class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i =0; i<n; i++){
            unordered_map<char,int>m;

            for(int j =i; j<n; j++){
                m[s[j]]++;
                int mnfreq = INT_MAX;
                int mxfreq = INT_MIN;            
                for(auto x: m){
                mnfreq = min(mnfreq,x.second);
                mxfreq = max(mxfreq,x.second);
            }
            sum = sum+mxfreq-mnfreq;

            }

        }
        return sum;
        
    }
};