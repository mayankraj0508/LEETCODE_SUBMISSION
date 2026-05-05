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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*temp = head;
        int n = 0;
        if(head==NULL||head->next==NULL){
            return head;
        }
    while(temp!=NULL){
       n++;
       temp =temp->next;
    }
      if(k>n){
        k = k%n;
    }
    if(k==n||k==0){
        return head;
    }
  

    ListNode*fast = head;
    for(int i =1;i<n-k; i++){
        fast = fast->next;
    }
    ListNode*left = fast;
    fast = fast->next;
    left->next = NULL;
    ListNode*h = fast;
   while(fast!=NULL&&fast->next){
    fast = fast->next;
   }
   if(fast){
   fast->next = head;
   }
    return h;
    }

};