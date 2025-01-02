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
       /* ek baarc check karna why not runn
        if(left==right){
            return head;
        }
        ListNode*temp  = head;
        for(int i =1; i<left-1; i++){
            temp = temp->next;
        }
        ListNode*c;
        if(temp==head){
            ListNode*c = head;
            
        }
        else{
        ListNode*c = temp->next;
        temp->next=NULL;
    
        }
        ListNode*tempc = c;
        
        for(int i = left; i<right; i++){
            tempc = tempc->next;
        }
        
        ListNode*d = tempc->next;
        tempc->next= NULL;
        ListNode*e = reverseList(c);
        ListNode*slow;
        if(left==1){
            ListNode*slow = e;
        }
        else{
        ListNode*slow = head;
        }
        while(slow->next!=NULL){
            slow = slow->next;
        }
        slow->next = e;
        if(left==1){
            return head;
        }
        slow = head;
        while(slow->next!=NULL){
            slow = slow->next;
        }
        slow->next = d;
        return head;*/
        if(left==right){
            return head;
        }
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
        c->next  = NULL;
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
};