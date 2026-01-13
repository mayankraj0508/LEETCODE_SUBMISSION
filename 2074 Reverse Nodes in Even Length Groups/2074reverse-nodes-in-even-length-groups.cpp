/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

       if(head==NULL||head->next==NULL){
            return head;
        }
            ListNode*newhead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newhead;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(left==right){
            return head;
        }
       
        ListNode*be = head;
        int sz = 0;
      
        ListNode*temp = head;
        int n = 1;
        ListNode*a = NULL;
        ListNode*b = NULL;
        ListNode*c = NULL;
        ListNode*d = NULL;

        while(temp!=NULL){
            if(n==left-1) a = temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right+1) d  = temp;
            n = n+1;
            temp = temp->next;
        }
        if(a!=NULL){
            a->next = NULL;

        }
       if(c) c->next  = NULL;
        c = reverseList(b);
        if(a!=NULL){
        a->next = c;
        }
        b->next = d;
        if(a!=NULL){
        return head;
        }
        else {
            return c;
        }
        
        
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode*temp = head;
        int gap = 1;
        int sz = 0;
         ListNode*te = head;
         while(te){
            sz++;
            te = te->next;
         }
    
         int count =1;
        while(temp&&temp->next){
            if(sz-count<=gap&&(sz-count)%2==0){
              cout<<count<<" ";
             temp =  reverseBetween(temp,2,2+gap);
            }
           else if(sz-count>gap&&gap%2!=0){
               temp =  reverseBetween(temp,2,2+gap);
            }
            gap++;
            int x = gap;
            while(temp&&x>0){
                temp = temp->next;
                count++;
                x--;

            }
           
        }
        return head;

        
    }
};