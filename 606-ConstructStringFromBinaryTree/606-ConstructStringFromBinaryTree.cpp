// Last updated: 02/05/2026, 22:44:08
class Solution {
public:
    void solve(TreeNode* root, string& ans) {
        if (!root) return;  // Base case: If node is null, return

        ans += to_string(root->val);  // Append current node's value

        if (root->left || root->right) {  // If at least one child exists
            ans += '(';
            solve(root->left, ans);
            ans += ')';
        }

        if (root->right) {  // If right child exists, add parentheses and recurse
            ans += '(';
            solve(root->right, ans);
            ans += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};