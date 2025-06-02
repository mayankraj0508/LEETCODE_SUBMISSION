    class Solution {
    public:
        string reverseWords(string s) {
        string ans ="";
        int n = s.size();
        string p;
        int i = n-1;
            while(i>=0){
            if(s[i]==' '){
                
                i--;
            }
            else{
                while(i>=0&&s[i]!=' '){
                    
                    p = p + s[i];
                    i--;
                }
                reverse(p.begin(),p.end());
            ans = ans + p+" ";
            
                
                p = "";
                i--;
            }
            }
            while(ans[ans.size()-1]==' '){
                ans.pop_back();
            }
            return ans;  
        }
    };