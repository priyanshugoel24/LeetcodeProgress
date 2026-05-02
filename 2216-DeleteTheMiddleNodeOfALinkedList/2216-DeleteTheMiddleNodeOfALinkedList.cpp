// Last updated: 02/05/2026, 22:37:13
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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            fast = fast->next->next;
            slow = slow->next;

        }

        ListNode* prev = head;

        while(prev->next != slow && slow != NULL){

            prev = prev->next;
        }

        prev->next = slow->next;

        return head;
        
    }
};