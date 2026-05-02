// Last updated: 02/05/2026, 22:44:57
class Solution {
public:
    struct TrieNode{
        TrieNode* left; // 0
        TrieNode* right; // 1
    };

    void insert(TrieNode* root, int &num){

        TrieNode* pCrawl = root;

        for(int i = 31; i >= 0; i--){

            int ith_bit = (num >> i) & 1;

            if(ith_bit == 0){

                if(pCrawl->left == NULL){
                    pCrawl->left = new TrieNode();
                }
                
                pCrawl = pCrawl->left;
            }else{

                if(pCrawl->right == NULL){
                    pCrawl->right = new TrieNode();
                }

                pCrawl = pCrawl->right;
            }
        }
    }

    int findMaxXor(TrieNode* root, int& num){

        int maxXor = 0;
        TrieNode* pCrawl = root;
        
        for(int i = 31; i >= 0; i--){

            int ith_bit = (num >> i) & 1;

            if(ith_bit == 1){

                if(pCrawl->left != NULL){
                    maxXor += pow(2, i);
                    pCrawl = pCrawl->left;
                }else{
                    pCrawl = pCrawl->right;
                }

            }else{

                if(pCrawl->right != NULL){
                    maxXor += pow(2, i);
                    pCrawl = pCrawl->right;
                }else{
                    pCrawl = pCrawl->left;
                }
            }
        }

        return maxXor;
    }
    int findMaximumXOR(vector<int>& nums) {
        
        TrieNode* root = new TrieNode();

        for(int &num : nums){
            insert(root, num);
        }

        int maxResult = 0;

        for(int i = 0; i < nums.size(); i++){

            int temp = findMaxXor(root, nums[i]);

            maxResult = max(maxResult, temp);
        }

        return maxResult;
    }
};