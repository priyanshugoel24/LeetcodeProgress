// Last updated: 02/05/2026, 22:47:02
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
    TreeNode* solve(TreeNode* root, vector<int>& ans){

        //base case
        if(root == NULL) return NULL;

        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);

        return root;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
        
    }
};