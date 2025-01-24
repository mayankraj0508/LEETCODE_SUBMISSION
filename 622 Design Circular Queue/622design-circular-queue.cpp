class MyCircularQueue {
public:
int f;//front
int b;
int s;//size
int c;//capacity of array
vector<int>arr;
    MyCircularQueue(int k) {//k = capacity
    f = 0;
    b= 0;
    s=0;
    c = k;
    vector<int>v(k);
    arr = v;
        
    }
    
    bool enQueue(int value) {//push back
    if(s==c){
        return false;
    }
    else{
        arr[b]= value;
        s++;
        b++;
        if(b==c){
            b = 0;
        }
        return true;
    }
        
    }
    
    bool deQueue() {//pop front
    if(s==0){
        return false;
    }
    f++;
    if(f==c){
        f = 0;
    }
    s--;
    return true;
        
    }
    
    int Front() {
        if(s==0){
            return -1;
        }
        else{
            return arr[f];
        }
        
    }
    
    int Rear() {
         if(s==0){
            return -1;
        }
        //yahan back se pehle last e;elementhee hoga 
        if(b==0)return arr[c-1];
        return arr[b-1];
        
    }
    
    bool isEmpty() {
        if(s==0){
            return true;
        }
        return false;
        
    }
    
    bool isFull() { //if size ==k
    if(s==c){
        return true;
    }
    return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */