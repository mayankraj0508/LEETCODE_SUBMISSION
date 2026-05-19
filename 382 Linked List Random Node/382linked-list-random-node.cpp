class Solution {
public:
    
    vector<int>v;

    Solution(ListNode* head) {
        ListNode*temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int n = v.size();
        int idx = rand()%n;
        return v[idx];
    }
};