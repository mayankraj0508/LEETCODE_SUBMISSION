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
    ListNode* deleteDuplicates(ListNode* head) {
           ListNode* temp = head;
    ListNode* pre  = head;

    while (head && head->next && head->val == head->next->val) {
        int data = head->val;
        while (head && head->val == data) {
            head = head->next;
        }
    }

    // ⭐⭐⭐ BAS YE LINE ⭐⭐⭐
    if (!head) return NULL;

    temp = head;
    pre  = head;

    while (temp) {
        while(temp && temp->next && temp->val == temp->next->val) {
            int data = temp->val;
            while (temp && temp->val == data) {
                temp = temp->next;
            }
            pre->next = temp;
        }
        pre = temp;
        if(temp)
        temp = temp->next;
    }
    return head;
        
    }
};