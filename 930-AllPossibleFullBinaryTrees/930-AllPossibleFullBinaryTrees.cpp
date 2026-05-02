// Last updated: 02/05/2026, 22:42:29
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
    vector<TreeNode*> solve(int n, unordered_map<int, vector<TreeNode*>>& dp){

        //base case
        //if even no of nodes no possibility of full binary tree
        if(n % 2 == 0){
            return {};
        }

        //one node can give only one full binary tree
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        vector<TreeNode*> result; // result vector to store roots of possible full binary trees

        for(int i = 1; i < n ; i += 2){

            vector<TreeNode*> leftFBT = solve(i, dp); // all possible full binary tree from left 
            vector<TreeNode*> rightFBT = solve( n - i - 1, dp); // all possible full binary tree from right

            for(auto &left : leftFBT){

                for(auto &right : rightFBT){

                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return dp[n] = result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> dp; // dp mapping to store no of full binary trees for a value n
        return solve(n, dp);

    }
};