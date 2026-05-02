// Last updated: 02/05/2026, 22:49:00
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
    ListNode* swapPairs(ListNode* head) {
        
        // base case : single or zero nodes
        if(!head) return head;
        if(!head->next) return head;

        // base case : only two nodes 
        if(head->next->next == NULL){

            head->next->next = head;
            ListNode* newHead = head->next;

            head->next = NULL;
            return newHead;
        }

        ListNode* rest = head->next->next;
        ListNode* swappedRest = swapPairs(rest);

        head->next->next = head;
        ListNode* newHead = head->next;

        head->next = swappedRest;

        return newHead;

    }
};