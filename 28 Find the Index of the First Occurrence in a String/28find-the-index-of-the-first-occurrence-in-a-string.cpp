class Solution {
public:
 vector<int>lps(string &s){
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
        return lps;
    
    }
    int strStr(string haystack, string needle) {
        vector<int>lp = lps(needle);
        lp[0] = 0;
     int i =0;
     int j =0;
     while(i<haystack.size()){
        //int j =0;
        if(haystack[i]==needle[j]){
            i++;
            j++;
            if(j==needle.size()){
                return i-j;
            }
        }
        else{
            if(j!=0){
            j  = lp[j-1];
            }
            else{
                i++;
            }
        }
     }
           return -1;
    }
};