// Last updated: 02/05/2026, 22:36:11
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findNode(TreeNode* root, int target){

        // base case : if reached end
        if(root == NULL){
            return NULL;
        }

        // base case : if reached the target node
        if(root->val == target){
            return root;
        }

        TreeNode* left = findNode(root->left, target);
        TreeNode* right = findNode(root->right, target);

        if(left) return left;
        if(right) return right;

        return NULL;
    }

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* curr = q.front(); q.pop();

            if(curr->left){
                q.push(curr->left);
                nodeToParent[curr->left] = curr;
            }

            if(curr->right){
                q.push(curr->right);
                nodeToParent[curr->right] = curr;
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {

        // if only one node
        if(root->left == NULL && root->right == NULL){
            return 0;
        }
        
        TreeNode* infectedStart = findNode(root, start);

        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        markParents(root, nodeToParent);

        int infectionTime = 0;

        queue<TreeNode*> q;
        q.push(infectedStart);

        unordered_map<TreeNode*, bool> visited;
        visited[infectedStart] = true;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                TreeNode* curr = q.front(); q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                TreeNode* parent = nodeToParent[curr];

                if(parent && !visited[parent]){
                    q.push(parent);
                    visited[parent] = true;
                }
            }

            infectionTime += 1;
        }


        return infectionTime - 1;

    }
};