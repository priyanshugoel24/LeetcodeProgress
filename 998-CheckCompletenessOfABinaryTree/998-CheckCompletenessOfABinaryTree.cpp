// Last updated: 02/05/2026, 22:42:06
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
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);

        return ans;
    }
    bool isCBT(TreeNode* root, int index, int nodes){

        if(root == NULL) return true;
        if(index >= nodes) return false;
        else{
            bool left = isCBT(root->left, 2*index+1, nodes);
            bool right = isCBT(root->right, 2*index+2, nodes);
            return left && right;
        }
    }
    bool isCompleteTree(TreeNode* root) {

        int index = 0;
        int nodes = countNodes(root);

        return isCBT(root, index, nodes);

        
        
    }
};