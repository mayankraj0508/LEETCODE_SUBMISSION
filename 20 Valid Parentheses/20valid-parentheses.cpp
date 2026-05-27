class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i =0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                char x = s[i];
                while(x==')' && st.size() && st.top()!='('){
                    if(st.top()=='{' || st.top()=='['){
                        return false;
                    }
                    st.pop();
                }
                 while(x=='}' && st.size() && st.top()!='{'){
                     if(st.top()=='(' || st.top()=='['){
                        return false;
                    }
                    st.pop();
                }
                 while(x==']' && st.size() && st.top()!='['){
                     if(st.top()=='{' || st.top()=='('){
                        return false;
                    }
                    st.pop();
                }
                if(st.size()==0){
                    return false;

                }
                st.pop();
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
        
    }
};