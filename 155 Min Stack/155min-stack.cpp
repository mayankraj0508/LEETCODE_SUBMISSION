#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int>st;
    stack<int>rt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(rt.size()==0){
            rt.push(val);
        }
        else if(val<=rt.top()){
            rt.push(val);
        }
        
    }
    
    void pop() {
        int a = st.top();
        st.pop();
        if(rt.top()==a){
            rt.pop();
        }

        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return rt.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */