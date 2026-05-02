// Last updated: 02/05/2026, 22:48:59
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy, *nextNode = dummy, *preNode = dummy;
        int count = 0;

        while(curr->next){
            curr = curr->next;
            count++;
        }

        while(count >= k){

            curr = preNode->next;
            nextNode = curr->next;

            for(int i = 1; i < k; i++){

                curr->next = nextNode->next;
                nextNode->next = preNode->next;
                preNode->next = nextNode;
                nextNode = curr->next;

            }

            preNode = curr;
            count -= k;
        }

        return dummy->next;
    }
};