// Last updated: 02/05/2026, 22:42:45
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent, TreeNode* target){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* curr = q.front(); q.pop();

            if(curr->left){
                nodeToParent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right){
                nodeToParent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        markParents(root, nodeToParent, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);

        visited[target] = true;

        int curr_dist = 0;

        while(!q.empty()){

            int size = q.size();

            if(curr_dist++ == k) break;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); q.pop();

                // traversing the left child
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                // traversing the right child
                if(curr->right && !visited[curr->right]){

                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                
                // traversing the parent
                if(nodeToParent[curr] && !visited[nodeToParent[curr]]){
                    q.push(nodeToParent[curr]);
                    visited[nodeToParent[curr]] = true;
                }
            }
        }


        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            result.push_back(curr->val);
        }

        return result;
    }
};