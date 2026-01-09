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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*slow = head;
        ListNode*fast = head;
        int n =k;
        for(int i =1; i<=n-1; i++){
            if(fast==NULL){
                return head;
            }
            fast = fast->next;
            
        }
        ListNode*temp1 = fast;
        if(fast){
            fast = fast->next;
        }
       
        while(fast!=NULL){
            slow = slow->next;
            fast=fast->next;
        }
        swap(slow->val,temp1->val);
        return head;
        
    }
};