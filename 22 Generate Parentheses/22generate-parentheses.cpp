class Solution {
public:
    vector<string>ans;
    void f(string s, int open, int close, int n){
        if(close>open){
            return ;
        }
        if(open>n||close>n){
            return ;
        }
        if(open==n && close ==n ){
            ans.push_back(s);
            return ;
        }
        if(open==close){
            f(s+'(',open+1,close,n);
        }
        else {
            f(s+'(',open+1,close,n);
            f(s+')',open,close+1,n);
        
        }
        

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        f(s,0,0,n);
        return ans;
      
        
    }
};