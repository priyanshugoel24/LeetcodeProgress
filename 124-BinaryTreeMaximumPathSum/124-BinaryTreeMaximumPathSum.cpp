// Last updated: 02/05/2026, 22:47:25
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
    int findMaxPath(TreeNode* root, int& max_sum){

        // base case : if node is not present
        if(root == NULL){
            return 0;
        }

        int leftSum = max(0, findMaxPath(root->left, max_sum));
        int rightSum = max(0, findMaxPath(root->right, max_sum));

        int currSum = root->val + leftSum + rightSum;

        max_sum = max(max_sum, currSum);

        int maxPath = root->val + max(leftSum, rightSum);

        return maxPath;
    }
    int maxPathSum(TreeNode* root) {
        
        int max_sum = INT_MIN;

        findMaxPath(root, max_sum);

        return max_sum;
       
    }
};