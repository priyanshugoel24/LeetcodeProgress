// Last updated: 02/05/2026, 22:44:50
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int p_length = p.length();
        int s_length = s.length();

        unordered_map<char,int> charFreqOfP;
        unordered_map<char, int> charFreqOfS;

        for(int i = 0; i < p_length; i++){

            charFreqOfP[p[i]]++;
            charFreqOfS[s[i]]++;
        }

        vector<int> anagramStartingIdx;

        if(charFreqOfP == charFreqOfS){
            anagramStartingIdx.push_back(0);

        }

        int i = 1, j = p_length;

        while(j < s_length){
            
            // decrement the frequency of previous character which is out of window now
            charFreqOfS[s[i-1]]--;

            // if frequency of char becomes zero, delete its key
            if(charFreqOfS[s[i - 1]] == 0){
                charFreqOfS.erase(s[i - 1]);
            }
            
            //increment the frequency of the new character in the window
            charFreqOfS[s[j]]++;

            // if still both maps are equal, this idx is a valid starting of anagram of p
            if(charFreqOfS == charFreqOfP){
                anagramStartingIdx.push_back(i);
            }

            // shift the window to right
            i++;
            j++;
        }


        return anagramStartingIdx;



    }
};