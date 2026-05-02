// Last updated: 02/05/2026, 22:47:54
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
    vector<TreeNode*> solve(int start, int end, map< pair<int,int> , vector<TreeNode*> > &mp){

        //base case : out of bound 
        if(start > end){
            return {NULL};
        }

        //base case : only one node
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        //if subproblem is already solved
        if(mp.find({start, end}) != mp.end()){
            return mp[{start, end}];
        }

        vector<TreeNode*> result;

        //making trees from start till end
        for(int i = start; i <= end; i++){

            vector<TreeNode*> leftBST = solve(start, i - 1, mp);
            vector<TreeNode*> rightBST = solve(i + 1, end, mp);

            //making combinations from left and right subtrees
            for(TreeNode* leftRoot : leftBST){

                for(TreeNode* rightRoot : rightBST){

                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);
                }
            }
        }

        return mp[{start, end}] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        map< pair<int,int>, vector<TreeNode*> > mp; //memoization map
        return solve(1, n, mp);
    }
};