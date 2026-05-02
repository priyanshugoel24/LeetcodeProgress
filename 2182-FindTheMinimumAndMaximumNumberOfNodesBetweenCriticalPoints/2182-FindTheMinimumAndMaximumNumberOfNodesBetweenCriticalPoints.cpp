// Last updated: 02/05/2026, 22:37:23
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

        if (!head || !head->next || !head->next->next) {
            return {-1, -1};  // Less than 3 nodes => can't have critical points
        }

        int position = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int first = -1, last = -1, prevCritical = -1;
        int minDist = INT_MAX;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                if (first == -1) {
                    first = position;
                } else {
                    minDist = min(minDist, position - prevCritical);
                }

                prevCritical = position;
                last = position;
            }

            prev = curr;
            curr = next;
            next = next->next;
            position++;
        }

        if (first == last) {
            return {-1, -1};  // Only 0 or 1 critical points
        }

        return {minDist, last - first};
    }
};
