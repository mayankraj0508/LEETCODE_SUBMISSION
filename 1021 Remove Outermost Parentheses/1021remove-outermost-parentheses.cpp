class Solution {
public:
    void  f(string &ans,string t){
        int i = 1;
        int a = 1;
        while(a>=1 && i<t.size()){
            if(t[i]=='('){
                a++;
            }
            else{
                a--;
            }
            if(a!=0){
            ans = ans+t[i];
            }
            i++;

        }

    }
    string removeOuterParentheses(string s) {
        int i = 0;
        string ans = "";
        while(i<s.size()){
            int count  = 0;
            string t  = "";
            while(i<s.size()){
                if(s[i]=='('){
                    count++;
                    t = t+s[i];
                    i++;
                }
                else{
                    count--;
                    t = t+s[i];
                    i++;
                }
                if(count==0){
                    break;
                }
            }
            f(ans,t);
        }
        return ans;

        
    }
};