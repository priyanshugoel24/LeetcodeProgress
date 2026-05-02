// Last updated: 02/05/2026, 22:39:47
class Solution {
public:
    int maxDiff(int num) {
        
        string max_str = to_string(num);
        string min_str = to_string(num);

        int idx = max_str.find_first_not_of('9');

        if(idx != string::npos){
            
            char ch = max_str[idx];
            replace(max_str.begin(), max_str.end(), ch, '9');
        }

        for(int i = 0; i < min_str.length(); i++){

            char ch = min_str[i];

            if( i == 0){

                if(ch != '1'){
                    replace(min_str.begin(), min_str.end(), ch, '1');
                    break;
                }
            }else if(ch != '0' && ch != min_str[0]){
                    replace(min_str.begin(), min_str.end(), ch, '0');
                    break;
            }
        }

        return stoi(max_str) - stoi(min_str);

    }
};