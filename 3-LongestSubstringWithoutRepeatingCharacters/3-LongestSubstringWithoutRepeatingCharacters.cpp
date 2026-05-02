// Last updated: 02/05/2026, 22:49:21
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int length_of_string = s.length();

        if(length_of_string == 0){
            return 0;
        }

        unordered_set<char> charPresent;

        int longest_substring_length = 1;
        

        int left_idx = 0, right_idx = 0;

        while(right_idx < length_of_string){

            char curr_char = s[right_idx];            
        
            // if adding the current character violates our window increment left pointer till we have a valid substring
            while(charPresent.find(curr_char) != charPresent.end()){
                charPresent.erase(s[left_idx]);
                left_idx++;
            }

            charPresent.insert(curr_char);
            
            int curr_substring_length = right_idx - left_idx + 1;

            longest_substring_length = max(longest_substring_length, curr_substring_length);

            right_idx++;

        }

        return longest_substring_length;
    }
};