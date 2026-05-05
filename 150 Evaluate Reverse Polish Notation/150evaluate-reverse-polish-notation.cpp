class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i =0; i<tokens.size(); i++){
            if(st.size()>=2 && tokens[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = a+b;
                st.push(val);
            }
             else if(st.size()>=2 &&tokens[i]=="-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = b-a;
                st.push(val);
            }
              else if(st.size()>=2 &&tokens[i]=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = b/a;
                st.push(val);
            }
              else if(st.size()>=2 && tokens[i]=="*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = b*a;
                st.push(val);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        if(st.size()==0){
            return 0;
        }
        return st.top();
        
    }
};