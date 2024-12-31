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
    ListNode* partition(ListNode* head, int x) {
        ListNode*lo= new ListNode(100);
       
        ListNode*templ = lo;
        ListNode*hi = new ListNode(200);
       
        ListNode*temph = hi;
        ListNode*fast = head;
        while(fast!=NULL){
            if(fast->val<x){
                templ->next = fast;
                templ = templ->next;
                fast = fast->next;
            }
            else{
                temph->next = fast;
                temph = temph->next;
                fast = fast->next;
            }
        }
     


        templ->next = hi->next;
        temph->next=NULL;
       
        return lo->next;

      

        
        
    }
};