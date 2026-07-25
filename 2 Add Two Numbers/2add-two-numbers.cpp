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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1 = l1;
        ListNode*temp2 = l2;
        int s1 = 0;
        int s2 = 0;
        ListNode*t1 = l1;
        ListNode*t2 = l2;
        while(t1){
            s1++;
            t1 = t1->next;
        }
        while(t2){
            s2++;
            t2 = t2->next;
        }
        if(s1<s2){
            return  addTwoNumbers(l2,l1);
        }
        int carry = 0;
        while(temp1 && temp2){
            int val = temp1->val+ temp2->val+carry;
            if(val<10){
                carry = 0;
            }
            if(val>=10){
                val = val%10;
                carry = 1;

            }
            temp1->val = val;
                if(temp1->next ==NULL && temp2->next==NULL && carry==1){
                ListNode*c = new ListNode(1);;
                temp1->next = c;
                temp1 = NULL;
                temp2 = NULL;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
          
        }        
        while(temp1){
            int val =  temp1->val+carry;
            if(val<10){
                carry = 0;
            }
            else{
                carry = 1;
                val = val%10;

            }
        
            temp1->val = val;
            if(temp1->next ==NULL && carry==1){
                ListNode*c = new ListNode(1);;
                temp1->next = c;
                break;
            }
            temp1 = temp1->next;

        }
        temp1 = temp2;
          while(temp1){
            int val =  temp1->val+carry;
            if(val<10){
                carry = 0;
            }
            else{
                carry = 1;
                val = val%10;

            }
            temp1->val = val;
            if(temp1->next ==NULL && carry==1){
                ListNode*c = new ListNode(1);;
                temp1->next = c;
                break;
            }
            
            temp1 = temp1->next;

        }
        return l1;
    }
};