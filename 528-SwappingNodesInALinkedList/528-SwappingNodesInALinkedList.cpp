// Last updated: 02/05/2026, 22:44:27
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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* kthNodeFromStart = NULL; // kth node from start of the list
        ListNode* kthNodeFromEnd = NULL; // kth node from end of the list

        // dummy pointer for traversing list
        ListNode* temp = head;

        while(temp){

            // if starting node is assigned at kth position, then only increment the ending node pointer
            if(kthNodeFromEnd != NULL){
                kthNodeFromEnd = kthNodeFromEnd->next;
            }

            k--; // decrement the value of k

            // if we have reached our kth node from start
            if(k == 0){

                kthNodeFromStart = temp;
                kthNodeFromEnd = head;
            }

            // point the dummy pointer to the next node
            temp = temp->next;
        }

        swap(kthNodeFromStart->val, kthNodeFromEnd->val);

        return head;
    }
};