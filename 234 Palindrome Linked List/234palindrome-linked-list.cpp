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
    ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*newhead = reverse(head->next);
        head->next->next  = head;
        head->next = NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next !=NULL && fast->next->next!=NULL ){
            slow = slow->next;
            fast  = fast->next->next;
        }
       
        ListNode*temp = slow->next;
        ListNode*rev = reverse(temp);
        slow->next = NULL;
        ListNode*t1 = head;
        ListNode*t2 = rev;
        while(t1 && t2){
            if(t1->val!=t2->val){
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;

        }
        return true;

        
    }
};