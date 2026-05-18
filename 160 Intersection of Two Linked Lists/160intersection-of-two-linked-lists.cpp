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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a = headA;
        ListNode*b = headB;
        int al = 0;
        int bl = 0;
        while(a){
            a = a->next;
            al++;
        } 
        while(b){
            b = b->next;
            bl++;
        }
        if(al>=bl){
            int diff = abs(al-bl);
            ListNode*tempa = headA;
            while(diff--){
                tempa = tempa->next;
            }
            ListNode*tempb = headB;
            while(tempa!=tempb && tempa!=NULL && tempb!=NULL){
                tempa = tempa->next;
                tempb = tempb->next;
            }
            return tempa;

        }
        else{
           return  getIntersectionNode(headB,headA);
        }
    }
};