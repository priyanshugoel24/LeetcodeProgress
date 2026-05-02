// Last updated: 02/05/2026, 22:46:58
class Solution {
public:
    string reverseWords(string s) {
        
        istringstream in(s);
        vector<string> words;
        string w;

        while(in >> w) words.push_back(w);

        string out;
        for(int i = (int)words.size() - 1; i >= 0; i--){

            if(!out.empty()){
                out += ' ';
            }

            out += words[i];
        }

        return out;
    }
};