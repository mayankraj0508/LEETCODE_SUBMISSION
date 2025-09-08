class MyQueue {
public:
    stack<int>st;
    stack<int>pt;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        
    }
    
    int pop() {
        while(st.size()>1){
            pt.push(st.top());
            st.pop();
        }
        int val = st.top();
        st.pop();
        while(pt.size()>0){
            st.push(pt.top());
            pt.pop();
        }
        return val;
        
    }
    
    int peek() {
            while(st.size()>0){
        pt.push(st.top());
        st.pop();
    }
    int val = pt.top();

        while(pt.size()>0){
            st.push(pt.top());
            pt.pop();
        }
        return val;
        
    }
    
    bool empty() {
        if(st.size()>0){
            return false;
        }
        return true;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */