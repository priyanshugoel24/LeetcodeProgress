// Last updated: 02/05/2026, 22:35:28
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
    long long kthLargestLevelSum(TreeNode* root, int k) {

       if(!root) return -1;
       priority_queue<long, vector<long>, greater<long>> pq;
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
        int size = q.size();
        long sum = 0;
        while(size > 0){
            TreeNode* temp = q.front();
            q.pop();
            sum += temp->val;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            size--;
        }

        pq.push(sum);

        if(pq.size() > k) pq.pop();
       }

       if(pq.size() < k) return -1;
       else return pq.top();
        
    }
};