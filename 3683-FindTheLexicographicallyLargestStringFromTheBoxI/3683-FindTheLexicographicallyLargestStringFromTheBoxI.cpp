// Last updated: 02/05/2026, 22:32:47
class Solution {
public:
    string answerString(string word, int numFriends) {
        
        // if there is only one friend
        if(numFriends == 1){

            // return the whole word
            return word;
        }

        //if there are more than 1 friends

        int n = word.length();

        string answer = "";

        for(int i = 0; i < n; i++){

            int substr_length = min(n - numFriends + 1, n - i);
            string substr = word.substr(i, substr_length);
            answer = max(answer, substr);
        }

        return answer;
    }
};