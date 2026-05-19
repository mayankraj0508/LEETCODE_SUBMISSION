

class MyLinkedList {
public:
    ListNode*head;
    ListNode*tail;
    int size ;
    MyLinkedList() {
        head  = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index>=size){
            return -1;
        }
        int k = 0;
        ListNode*temp = head;
        while(k!=index && temp){
            temp = temp->next;
            k++;
        }
        if(temp==NULL){
            return -1;
        }
        else{
            return temp->val;
        }
        
    }
    
    void addAtHead(int val) {
        ListNode*c = new ListNode(val);
        c->next = head;
        head = c;
        if(size==0){
            tail = c;
        }
        size++;
        
    }
    
    void addAtTail(int val) {
        ListNode*t = new ListNode(val);
        if(size==0){
            head = tail = t;
            size++;
            return ;
        }
        if(tail!=NULL)
        tail->next = t;
        tail = t;
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        ListNode*c = new ListNode(val);
        int k = 0;
        if(index>size){
            return ;
        }
        if(index==0){
            addAtHead(val) ;
           
            return ;
        }
        else if(index==size){
            addAtTail(val);
         
            return ;
        }
        ListNode*temp = head;
        while(k!=index-1 && temp){
            temp = temp->next;
            k++;
        }
        c->next = temp->next;
        temp->next = c;
        size++;
        return ;
    } 
    
    void deleteAtIndex(int index) {
        if(index>=size){
            return ;
        }
        if(index==0){
            head = head->next;
            size--;
            return ;
        }
        int k = 0;
        ListNode*temp = head;
        while(k!=index-1 && temp){
           temp = temp->next;
           k++;
        } 
        if(temp && temp->next)
        temp->next = temp->next->next;
        if(index==size-1){
            tail  = temp;
        }
        size--;
        return ;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */