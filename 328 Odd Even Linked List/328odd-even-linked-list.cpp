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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*c = new ListNode(100);
        ListNode*tempo = c;
        ListNode*d = new ListNode(200);
        ListNode*tempe = d;
        ListNode*fast = head;
        while(fast!=NULL){
            tempe->next = fast;
            tempe = tempe->next;
            fast = fast->next;
            if(fast==NULL){
                break;
            }
            tempo->next = fast;
            tempo = tempo->next;
           
           
            
            fast=fast->next;
            
            




        }
        tempo->next = NULL;
        tempe->next = c->next;
       
        return d->next;



        
    }
};