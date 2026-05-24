class Solution {
public:
  
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
         
         while(i<s.size()){
            int j = i;
             if(s[j]==' '){
               ans = ans+s[j];
               j++;
             }
             else if(s[j]!=' '){
                while(j<s.size() && s[j]!=' '){
                    j++;
                }
                string p = s.substr(i,j-i);
                reverse(p.begin(),p.end());
                ans =ans+p;
             }
             i = j;
         }
         return ans;
        
    }
};