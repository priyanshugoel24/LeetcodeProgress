// Last updated: 02/05/2026, 22:46:16
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
    int findLeftHeight(TreeNode* root){

        int height = 0;

        while(root){
            height++;
            root = root->left;
        }

        return height;
    }

    int findRightHeight(TreeNode* root){

        int height = 0;

        while(root){
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }

        int totalNodes = 0;

        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        // in case subtree is a cbt nodes will be just 2^n - 1
        if(leftHeight == rightHeight){
            totalNodes = (1 << leftHeight) - 1;
        }

        totalNodes = 1 + countNodes(root->left) + countNodes(root->right);

        return totalNodes;
    }
};