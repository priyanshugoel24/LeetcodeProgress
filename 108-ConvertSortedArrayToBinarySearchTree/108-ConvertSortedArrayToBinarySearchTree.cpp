// Last updated: 02/05/2026, 22:47:39
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

    TreeNode* convertToBST(int l, int r, vector<int>& nums){

        if(l > r){ 
            return NULL;
        }

        if(l == r){ 
            return new TreeNode(nums[l]);
        }

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convertToBST(l, mid - 1, nums);
        root->right = convertToBST(mid + 1, r, nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();
        return convertToBST(0, n - 1, nums);
    }
};