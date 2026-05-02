// Last updated: 02/05/2026, 22:46:53
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
    int length(ListNode* head){

        ListNode* temp = head;

        int cnt = 0;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int lenA = length(headA);
        int lenB = length(headB);
        
       if(lenA > lenB){
        while(lenA > lenB){
            tempA = tempA->next;
            lenA--;
        }
       }
       else if( lenA < lenB){
        while(lenA < lenB){
            tempB = tempB->next;
            lenB--;
        }
       }

       while(tempA && tempB){
        if(tempA == tempB){
            return tempA;
        }

        tempA = tempA->next;
        tempB = tempB->next;

       }

       return NULL;
        
    }

    
};