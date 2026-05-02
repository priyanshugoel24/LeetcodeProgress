// Last updated: 02/05/2026, 22:42:12
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
    int dfs(TreeNode* root, int low, int high){

        // leaf node
        if(root->left == NULL && root->right == NULL){
            if(root->val >= low && root->val <= high){
                return root->val;
            }else{
                return 0;
            }
        }

        int range_sum = 0;

        range_sum += (root->val >= low && root->val <= high) ? root->val : 0;

        if(root->left){
            range_sum += dfs(root->left, low, high);
        }

        if(root->right){
            range_sum += dfs(root->right, low, high);
        }

        return range_sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        return dfs(root, low, high);
    }
};