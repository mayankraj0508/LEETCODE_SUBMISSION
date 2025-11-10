class Solution {
public:
    int lps(string &s){
        vector<int>lps(s.size());
        int  pre = 0;
        int suf =1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf] = pre+1;
                suf++;
                pre++;

            }
            else {
                if(pre==0){
                    lps[suf] =0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        return lps[lps.size()-1];
    
    }
    string longestPrefix(string s) {
        int idx = lps(s);
        string ans = s.substr(0,idx);
        return ans;
        
    }
};