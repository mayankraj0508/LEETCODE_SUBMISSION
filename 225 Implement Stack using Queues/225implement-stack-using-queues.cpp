class MyStack {
public:
        queue<int>a;
        queue<int>b;
    MyStack() {


        
    }
    
    void push(int x) {
        a.push(x);
        
    }
    
    int pop() {
        while(a.size()>1){
            b.push(a.front());
            a.pop();
        }
        int val = a.front();
        a.pop();
        while(b.size()>0){
            a.push(b.front());
            b.pop();
        }
        return val;
        
    }
    
    int top() {
          while(a.size()>1){
            b.push(a.front());
            a.pop();
        }
        int val = a.front();
        a.pop();
        while(b.size()>0){
            a.push(b.front());
            b.pop();
        }
        a.push(val);
        return val;
        
    }
    
    bool empty() {
        if(a.size()>0){
            return false;
        }
        
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */