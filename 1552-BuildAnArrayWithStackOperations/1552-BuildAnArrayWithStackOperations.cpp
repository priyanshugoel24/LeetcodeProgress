// Last updated: 02/05/2026, 22:39:41
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> result;

        string push = "Push";
        string pop = "Pop";

        int i = 1;
        int j = 0;
        while(j < target.size()){

            int curr_no = target[j];

            if(curr_no == i){
                result.push_back(push);
                i++,j++;
                continue;
            }

            while(i != curr_no){

                result.push_back(push);
                result.push_back(pop);
                i++;
            }

        }

        return result;
    }
};