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
    void reorderList(ListNode* head) {
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
          
            slow = slow->next;
              fast = fast->next->next;

        }
        ListNode*a = reverseList(slow->next);
       
        slow->next = NULL;
       
        ListNode*e  = new ListNode(100);
        ListNode*tempe = e;
        slow = head;
        ListNode*tempa = a;
        while(slow!=NULL){
            tempe->next = slow;
            slow = slow->next;
            tempe = tempe->next;
            tempe->next = tempa;
            if(tempa==NULL){
                break;
            }
            tempa = tempa->next;
            tempe = tempe->next;
        }
        tempe->next = NULL;
        e = e->next;
        cout<<e;

        
    }
};