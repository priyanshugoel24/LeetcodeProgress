// Last updated: 02/05/2026, 22:43:55
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
class BSTIterator {
    stack<TreeNode*> myStack;
    // reverse -> true -> before
    // reverse -> false -> next;

    bool reverse = true;
    void pushAll(TreeNode* node){

        while(node != NULL){
            myStack.push(node);

            if(!reverse){
                node = node->left;
            }else{
                node = node->right;
            }
            
        }
    }
    public:
        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }
        
        int next() {
            
            TreeNode* temp = myStack.top();
            myStack.pop();

            if(!reverse) pushAll(temp->right);
            else pushAll(temp->left);
            return temp->val;
        }
        
        bool hasNext() {
            
            return !myStack.empty();
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){

            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};