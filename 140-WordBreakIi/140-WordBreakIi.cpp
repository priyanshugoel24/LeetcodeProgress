// Last updated: 02/05/2026, 22:47:07
class Solution {
public:
    void solve(int idx, string& currSentence, string s, unordered_set<string>& st, vector<string>& result){

        //base case
        if(idx >= s.length()){
            result.push_back(currSentence);
            return;
        }

        for(int j = idx; j < s.length(); j++){
            string tempWord = s.substr(idx, j-idx+1);
            if(st.count(tempWord)){
                string temp = currSentence;
                if(!currSentence.empty()){
                    currSentence += " ";
                }
                currSentence += tempWord;
                solve(j+1, currSentence, s, st, result);
                currSentence = temp;

            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string& word : wordDict){
            st.insert(word);
        }
        vector<string> result;
        string currSentence = "";

        solve(0, currSentence, s, st, result);

        return result;
    }
};