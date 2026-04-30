class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>m;
        int n = s.size();
        for(int i =0; i<n; i++){
            m[s[i]]++;
        }
        int odd = 0;
        int even = INT_MAX;
        for(auto x:m){
            if(x.second%2==0){
                even = min(even,x.second);
            }
            else{
                odd = max(odd,x.second);
            }
        }
        return odd-even;
        
    }
};