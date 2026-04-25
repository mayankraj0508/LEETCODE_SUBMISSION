class Solution {
public:
    
    vector<string>sub;
    bool check(unordered_map<char,int>&m,char ch){
        
        int freq = m[ch];
        for(auto x:m ){
            if(x.second!=freq){
                return false;
            }
        }
        return true;
    }
   
    int longestBalanced(string s) {
        int ans = 0;
        for(int i =0; i<s.size(); i++){
            unordered_map<char,int>m;
            for(int j=i ; j<s.size(); j++){
                m[s[j]]++;
                if(check(m,s[j])){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
        
        
    }
};