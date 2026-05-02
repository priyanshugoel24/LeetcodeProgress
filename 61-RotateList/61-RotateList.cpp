// Last updated: 02/05/2026, 22:48:24
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1) Find length and the tail
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // 2) Normalize k
        k %= n;
        if (k == 0) return head;

        // 3) Make it a ring
        tail->next = head;

        // 4) New tail is (n - k - 1) steps from head
        int steps = n - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < steps; ++i) newTail = newTail->next;

        // 5) New head is next of newTail; break the ring
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
