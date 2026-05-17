/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow= head;
        if(head==NULL){
            return false;
        }
        ListNode*fast = head->next;
        while(fast !=NULL && fast->next!=NULL && slow!=fast){
            slow = slow->next;
            fast=fast->next->next;

        }
        if(fast==NULL || fast->next==NULL){
            return false;
        }
        return true;
        
    }
};