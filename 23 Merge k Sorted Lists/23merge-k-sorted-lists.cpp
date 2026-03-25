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
    class cmp{
       public:
        bool operator()(ListNode*a,ListNode*b){
            if(a && b){
            return a->val>b->val;
            }
            //just for maintraing the function signature 
            else{
                return false;
            }
        }

    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,cmp> pq;
        int n = lists.size();
        for(int i =0; i<n; i++){
           if(lists[i])
            pq.push(lists[i]);
        }
        ListNode*dummy = new ListNode(-1);
        ListNode*temp = dummy;
        while(pq.size()){
            ListNode*tem = pq.top();
            ListNode*a = NULL;
            if(tem){
                a = tem->next;
            }
            pq.pop();
            if(temp ){
            temp->next  = tem;
            if(tem)
            tem->next = NULL;
            temp = temp->next;
            }
            if(a)
            pq.push(a);
        }
        dummy = dummy->next;
        return dummy;

    }
};