class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* newHead = NULL;

        while (true) {
            ListNode* a = temp;

            // ✅ NULL check added
            for (int i = 1; i < k && a; i++) {
                a = a->next;
            }
            if (a == NULL) break;

            ListNode* b = a->next;
            a->next = NULL;

            // ✅ Node -> ListNode
            ListNode* rev = reverse(temp);

            if (newHead == NULL) {
                newHead = rev;
            }

            if (prev) {
                prev->next = rev;
            }

            ListNode* t = rev;
            for (int i = 1; i < k; i++) {
                t = t->next;
            }

            t->next = b;
            prev = t;
            temp = b;
        }

        return newHead ? newHead : head;
    }
};
