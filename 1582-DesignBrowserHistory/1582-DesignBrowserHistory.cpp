// Last updated: 02/05/2026, 22:39:30
class Node{

    public:
    string val;
    Node* prev;
    Node* next;

    Node(string data){
        val = data;
        prev = next = nullptr;
    }
};
class BrowserHistory {
public:
    Node* head = nullptr;
    Node* tracker = nullptr;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        tracker = head;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        tracker->next = newNode;
        newNode->prev = tracker;
        tracker = newNode;
    }
    
    string back(int steps) {
        
        while(tracker->prev && steps--){
            tracker = tracker->prev;
        }

        return tracker->val;
    }
    
    string forward(int steps) {
        
        while(tracker->next && steps--){
            tracker = tracker->next;
        }

        return tracker->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */