// Last updated: 02/05/2026, 22:36:34
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
    bool validateSum(TreeNode* root){

        if(root->left == NULL && root->right == NULL){
            return true;
        }

        bool sumCondn = (root->val) == (root->left->val + root->right->val);

        bool leftAns = validateSum(root->left);
        bool rightAns = validateSum(root->right);

        if(sumCondn && leftAns && rightAns){
            return true;
        }

        return false;
    }
    bool checkTree(TreeNode* root) {
        
        return validateSum(root);
    }
};