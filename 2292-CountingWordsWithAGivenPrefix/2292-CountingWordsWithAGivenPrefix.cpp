// Last updated: 02/05/2026, 22:36:52
struct trieNode{
    trieNode* children[26];
    bool isEndofWord;
    int count; // no of prefix ending at this node
};

trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode->isEndofWord = false;
    newNode->count = 0;

    for(int i = 0; i<26; i++){
        newNode->children[i] = NULL;
    }

    return newNode;
}

class Trie{
    public:
    trieNode* root;

    Trie(){
        root = getNode();
    }

    void insert(string word){
        trieNode* pCrawl = root;
        for(char &ch : word){
            int idx = ch - 'a';

            if(pCrawl->children[idx] == NULL){
                pCrawl->children[idx] = getNode();
            }

            pCrawl = pCrawl->children[idx];
            pCrawl->count++;
        }

        pCrawl->isEndofWord = true;

    }

    int searchPrefixCount(string &pref){
        trieNode* pCrawl = root;
        for(char &ch : pref){
            int idx = ch - 'a';

            if(pCrawl->children[idx] == NULL) return 0;

            pCrawl = pCrawl->children[idx];
        }

        return pCrawl->count;
    }
};


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        Trie trie;

        for(string &word : words){
            trie.insert(word);
        }

        return trie.searchPrefixCount(pref);
        
    }
};