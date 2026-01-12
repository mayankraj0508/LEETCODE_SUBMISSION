class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>v;
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }

        int quo = len/k;
        int rem = len%k;

        if(rem==len){
           ListNode*tem = head;
           ListNode*b = head;
           while(tem){
            tem = b;
            if(b == NULL) break;      
            b = tem->next;
            tem->next = NULL;
            v.push_back(tem);
           }
        }
        else{
            

                if(head == NULL) return v;   

                ListNode*tem = head;
                int x = quo+1;

                while(rem-- > 0){

                    if(tem == NULL) break;  

                    ListNode*b = tem;
                    for(int i =1; i<x && b!=NULL; i++){
                        b = b->next;      
                    }

                    if(b == NULL) break; 

                    ListNode*c = b->next;
                    b->next = NULL;
                    v.push_back(tem);
                    tem = c;
                    head = c;              
                }

                x = quo;
                while(tem){

                    ListNode*b = tem;
                    for(int i =1; i<x && b!=NULL; i++){
                        b = b->next;      
                    }

                    if(b == NULL) break;   

                    ListNode*c = b->next;
                    b->next = NULL;
                    v.push_back(tem);
                    tem = c;
                    head = c;
                }
            
        }
        if(v.size()<k){
            int n = v.size();
            int remain = k-v.size();
            while(remain>0){
                v.push_back(NULL);
                remain--;
            }
           
        }
        return v;
    }
};
