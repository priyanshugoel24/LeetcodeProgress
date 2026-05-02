// Last updated: 02/05/2026, 22:43:48
class Solution {
public:

    void calculate(vector<double>& possibilities, double num1, double num2){

        // computer results using all 4 mathematical operations
        possibilities.push_back(num1 + num2);
        possibilities.push_back(num1 - num2);
        possibilities.push_back(num1 * num2);
        if(num2 != 0) possibilities.push_back(num1 / num2);

        possibilities.push_back(num2  - num1);
        if(num1 != 0) possibilities.push_back(num2 / num1);

    }
    bool solve(vector<double>& nums){

        int n = nums.size();

        double error_margin = 1e-5;

        // base case : if we have only 1 number remaining check if it is equal to our required number
        if(n == 1){

            return fabs(nums[0] - 24.0) < error_margin;
        }

        // pick two numbers and then try all possibilities
        for(int i = 0; i < n; i++){

            for(int j = i + 1; j < n; j++){

                double num1 = nums[i], num2 = nums[j];

                // take the remaining numbers
                vector<double> remaining;
                for(int k = 0; k < n; k++){

                    if(k == i || k == j) continue;
                    remaining.push_back(nums[k]);
                }

                // calculate all results from num1 and num2 then try to reach 24 from it 
                vector<double> possibilities;
                calculate(possibilities, num1, num2);

                for(auto& possibility : possibilities){

                    remaining.push_back(possibility);

                    if(solve(remaining)){
                        return true;
                    }

                    remaining.pop_back();
                }
            }
        }

        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        
        // convert the original cards to real numbers
        vector<double> nums(4);
        for(int i = 0; i < 4; i++){

            nums[i] = (double)(cards[i]);
        }

        return solve(nums);
    }
};