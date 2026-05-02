// Last updated: 02/05/2026, 22:40:29
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
    int getDecimalValue(ListNode* head) {
        
        ListNode* temp = head;
        int num = 0;

        while(temp != nullptr){

           num = (num << 1) | temp->val;

            temp = temp->next;
        }

        return num;


    }
};