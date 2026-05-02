// Last updated: 02/05/2026, 22:47:43
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool flag = false;

        while(!q.empty()){
            int size = q.size();
            vector<int> lvl;

            while(size--){
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);

                }

                lvl.push_back(frontNode->val);
            }

            if(flag){
                reverse(begin(lvl), end(lvl));                
            }
            flag = !flag;
            result.push_back(lvl);
        }

        return result;

        
    }
};