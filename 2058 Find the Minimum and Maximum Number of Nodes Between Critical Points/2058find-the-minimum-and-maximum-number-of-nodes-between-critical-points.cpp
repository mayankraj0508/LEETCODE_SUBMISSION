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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      ListNode*temp = head;
      int idx = 0;
      int count = 0;
      int first;
      int pre ;
      int last  = 1;
         int ans1 =  INT_MAX;
        int ans2 = INT_MIN;
      while(temp){
       
  
        if(temp->next&&temp->next->next){
            if(temp->next->val>temp->next->next->val&&temp->next->val>temp->val){
                count++;
         
                if(count==1){
                    first = idx+1;
                    last = idx+1;
                    pre = idx+1;
                }
                else{
                    ans1 = min(ans1,idx+1-pre);
                    last = idx+1;
                    pre = idx+1;
                  
                }

            }
        else if(temp->next->val<temp->next->next->val&&temp->next->val<temp->val){
                  count++;
          
                if(count==1){
                    first = idx+1;
                    last = idx+1;
                    pre = idx+1;
                }
                else{
                    ans1 = min(ans1,idx+1-pre);
                    pre = idx+1;
                    last = idx+1;
                  
                }

        }
        
      }
      idx++;
        temp = temp->next;
      }
      ans2 = last-first;
  
      if(count<2){
        return {-1,-1};
      }
      return {ans1,ans2};
        
    }
};