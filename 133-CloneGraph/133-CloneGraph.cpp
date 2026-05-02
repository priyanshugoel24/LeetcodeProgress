// Last updated: 02/05/2026, 22:47:16
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr) return nullptr;

        unordered_map<Node* , Node*> cloneGraph; // mapping of original to clone
        queue<Node*> q;

        Node* new_root = new Node(node->val);
        cloneGraph[node] = new_root;
        q.push(node);

        while(!q.empty()){

            Node* curr = q.front();
            q.pop();

            for(auto& nbr : curr->neighbors){

                if(cloneGraph.find(nbr) == cloneGraph.end()){

                    cloneGraph[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }

                cloneGraph[curr]->neighbors.push_back(cloneGraph[nbr]);
            }
        }

        return new_root;

        
    }
};