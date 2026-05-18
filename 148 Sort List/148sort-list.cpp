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
    ListNode*merge(ListNode*a, ListNode*b){
        ListNode*c = new ListNode(100);
        ListNode*tempc = c;
        ListNode*tempa = a;
        ListNode*tempb = b;
        while(tempa && tempb){
            if(tempa->val<tempb->val){
                tempc->next = tempa;
                tempc = tempc->next;
                tempa = tempa->next;
            }
            else{
                tempc->next = tempb;
                tempc = tempc->next;
                tempb = tempb->next;
            }
        }
        if(tempa){
            tempc->next = tempa;
        }
        if(tempb){
            tempc->next = tempb;
        }
        c = c->next;
        return c;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
           return head;
        }
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast  && fast->next && fast->next->next){
            slow = slow->next;
            fast  = fast->next->next;

        }
        
        ListNode*b = slow->next;
        slow->next = NULL;
        ListNode*a = head;
        a = sortList(a);
        b = sortList(b);
        return  merge(a,b);
    }
};