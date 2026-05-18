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
    ListNode*reversel(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*newhead = reversel(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode*a = reversel(head);
        ListNode*temp = a;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        vector<int>nge(len);
        ListNode*b = a;
        stack<int>st;
        int i = 0;
        while(b){
            if(st.size()==0){
            st.push(b->val);
            nge[i] = 0;
            i++;
        }
        else{
            while(st.size()  && st.top()<=b->val){
                st.pop();
            }
            if(st.size()==0){
             nge[i] = 0;
             st.push(b->val);
             i++;
            }
            else{
                nge[i] = st.top();
                st.push(b->val);
                i++;
            }
        }
        b = b->next;
            

        }
        reverse(nge.begin(),nge.end());
        return nge;
        
    }
};