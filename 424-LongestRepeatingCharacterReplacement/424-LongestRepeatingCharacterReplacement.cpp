// Last updated: 02/05/2026, 22:44:56
class Solution {
public:
    int characterReplacement(string s, int k) {

       int length_of_string = s.length();

       int longest_valid_substring_length = 0;

       for(char ch = 'A'; ch <= 'Z'; ch++){

        int left = 0, right = 0, changes = 0;

        while(right < length_of_string){

            char curr_char = s[right];

            if(curr_char != ch){
                changes++;
            }

            while(changes > k){

                if(s[left] != ch){
                    changes--;
                }

                left++;
            }

            int curr_valid_substring_length = right - left + 1;

            longest_valid_substring_length = max(longest_valid_substring_length, curr_valid_substring_length);

            right++;
        }
       }


       return longest_valid_substring_length;
    }
};