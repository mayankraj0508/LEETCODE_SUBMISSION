class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string t;
        for(int i =0; i<n; i++){
            if(s[i]>='A'&&s[i]<='Z'){
                t.push_back(s[i]+32);
            }
            else if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){
                t.push_back(s[i]);
            }
        }
        string rev = t;
        reverse(rev.begin(),rev.end());
        for(int i =0;i<t.size();i++){
            if(t[i]!=rev[i]){
                return false;
            }
        }
        return true;
     
    
        
    }
};