// Last updated: 02/05/2026, 22:43:54
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

typedef unsigned long long ULL;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root){
            return 0;
        }

        ULL max_width = 0;

        queue<pair<TreeNode*, ULL>> q;
        // q -> {node, idx}

        q.push({root, 0});

        while(!q.empty()){

            int size = q.size();
            ULL first_idx = 0;
            ULL last_idx = 0;

            ULL min_idx = q.front().second;


            for(int i = 0; i < size; i++){
                
                auto [node, curr_idx] = q.front();
                q.pop();

                curr_idx -= min_idx;

                if(i == 0){
                    first_idx = curr_idx;
                }

                if(i == size - 1){
                    last_idx = curr_idx;
                }

                if(node->left){
                    q.push({node->left, curr_idx*2+ 1});
                }

                if(node->right){
                    q.push({node->right, 2*curr_idx + 2});
                }
            }

            max_width = max(max_width, last_idx - first_idx + 1);
        }

        return (int)max_width;
    }

};