// Last updated: 02/05/2026, 22:41:10
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        unordered_map<int, ListNode*> mp;

        int currSum = 0;
        ListNode* temp = head;

        // 1) Link dummy to the original head and map sum 0 to dummy
        ListNode* zeroNode = new ListNode(0);
        zeroNode->next = head;                
        mp[0] = zeroNode;

        while (temp) {
            currSum += temp->val;

            if (mp.find(currSum) == mp.end()) {
                // first time seeing this prefix sum
                mp[currSum] = temp;
            } else {
                // we saw this sum before: remove the zero-sum segment in between
                ListNode* start = mp[currSum];

                // Erase intermediate prefix sums between start->next and temp
                int s = currSum;
                ListNode* node = start->next;
                while (node != temp) {
                    s += node->val;           // sums strictly inside the segment
                    mp.erase(s);
                    node = node->next;
                }

                // Splice out [start->next ... temp]
                start->next = temp->next;
            }

            temp = temp->next;
        }

        // 2) Return the possibly new head
        return zeroNode->next;
    }
};
