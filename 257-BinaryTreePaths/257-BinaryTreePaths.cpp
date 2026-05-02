// Last updated: 02/05/2026, 22:45:56
class Solution {
public:
    void findPaths(TreeNode* root, string& currPath, vector<string>& paths) {
        if (!root) return;

        // Store original length before modifying
        int originalLength = currPath.length();

        // Add current node's value
        currPath += to_string(root->val);

        // If it's a leaf, add path to result
        if (!root->left && !root->right) {
            paths.push_back(currPath);
        } else {
            currPath += "->";  // Add separator for further children
            findPaths(root->left, currPath, paths);
            findPaths(root->right, currPath, paths);
        }

        // Backtrack: remove appended part
        currPath.resize(originalLength);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string currPath = "";

        findPaths(root, currPath, paths);
        return paths;
    }
};
