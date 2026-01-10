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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*a =  l1;
        ListNode*b = l2;
        ListNode*fina = new ListNode(-1);
        ListNode*c = fina;
        while(a&&b){
            if(a->val<b->val){
                ListNode*temp = new ListNode(a->val);
                c->next = temp;
                c = c->next;
                a= a->next;

            }
            else if(a->val==b->val){
                ListNode*temp = new ListNode(a->val);
                c->next = temp;
                c= c->next;
                ListNode*temp2 = new ListNode(a->val);
                c->next = temp2;
                c= c->next;
                a = a->next;
                b = b->next;
            }
            else{
                ListNode*temp = new ListNode(b->val);
                c->next = temp;
                c = c->next;
                b= b->next;

            }
        }
        if(a==NULL&&b){
            // while(b){
            //     ListNode*temp = new ListNode(b->val);
            //     c->next = temp;
            //     c= c->next;
            //     b   = b->next;
            // }
            c->next = b;
        }
        else if(b==NULL&&a){
            c->next = a;

        }
        fina = fina->next;
        return fina;
        
    }
};