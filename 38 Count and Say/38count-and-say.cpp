class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string str =countAndSay(n-1);
        string ans ="";
        char ch = str[0];
        int freq = 1;
        for(int i=1; i<str.size(); i++){
            char dh = str[i];
            if(ch==dh){
             freq++;
            }
            else{
                ans = ans + (to_string(freq)+ch);
                freq = 1;
                ch = str[i];
            }
        }
           ans = ans + (to_string(freq)+ch);
           return ans;

        
    }
};