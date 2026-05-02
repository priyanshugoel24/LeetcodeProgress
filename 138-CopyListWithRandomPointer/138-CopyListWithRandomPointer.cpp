// Last updated: 02/05/2026, 22:47:10
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;

        // Step 1: Insert copied nodes
        while (temp) {
            Node* nextNode = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextNode;
            temp = nextNode;
        }

        // Step 2: Assign random pointers
        temp = head;
        while (temp) {
            Node* copyNode = temp->next;
            copyNode->random = temp->random ? temp->random->next : nullptr;
            temp = copyNode->next;
        }

        // Step 3: Separate the two lists
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while (original) {
            original->next = copy->next;
            original = original->next;
            if (original) {
                copy->next = original->next;
                copy = copy->next;
            }
        }

        return copyHead;
    }
};
