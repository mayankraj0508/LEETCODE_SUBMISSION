class Solution {
public:
    string f(string &s, string ans){
        int n = s.size();
        int i =0;

        while(i<=n-2){
            if(abs((int)s[i]-(int)s[i+1])==32){
                i = i+2;
            }
            else{
                ans = ans+s[i];
                i++;
            }
        }
        if(i==n-1){
            ans = ans+s[i];
        }
        return ans;
    }
    string makeGood(string s) {
        string ans = "";
        while(true){
             ans = "";
            ans = f(s,ans);
            if(ans==s){
                break;
            }
            s = ans;
           

        }
        return ans;
        
    }
};