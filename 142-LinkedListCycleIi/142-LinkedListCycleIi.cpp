// Last updated: 02/05/2026, 22:47:04
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* cycle(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return slow;
            }
        }

        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* intersection = cycle(head);

        if(intersection != NULL){
            while(slow != intersection){
                slow = slow->next;
                intersection = intersection->next;
            }
            
            return slow;
        }
        else{
            return NULL;
        }

        
        
    }
};