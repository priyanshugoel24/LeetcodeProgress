// Last updated: 02/05/2026, 22:41:25
class Solution {
public:
    void solve(vector<int>& people_skill, int idx, int target_mask,
               vector<int>& temp, int mask, vector<int>& result, unordered_map<string, int>& dp) {

        if (idx == people_skill.size()) {

            if (mask == target_mask) {
                // all bits are 1

                if (result.size() == 0 || result.size() >= temp.size()) {
                    result = temp;
                }
            }
            return;
        }

        string key = to_string(idx) + "_" + to_string(mask);

        if(dp.find(key) != dp.end()){

            if(dp[key] <= temp.size()){
                return;
            }
        }

        // bound the branch if already a better answer exists
        if (result.size() != 0 && temp.size() >= result.size()) {
            return;
        }

        // skip
        solve(people_skill, idx + 1, target_mask, temp, mask, result, dp);

        // take
        if ((mask | people_skill[idx]) != mask) {
            temp.push_back(idx);
            solve(people_skill, idx + 1, target_mask, temp,
                  mask | people_skill[idx], result, dp);
            // backtrack
            temp.pop_back();

            dp[key] = (temp.size() != 0) ? temp.size() : -1;
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {

        int n = req_skills.size(); // total no of skills
        int m = people.size();     // total no of people

        unordered_map<string, int> dp;

        // skill -> unique number
        unordered_map<string, int> skills;

        for (int i = 0; i < n; i++) {
            string skill_name = req_skills[i];
            skills[skill_name] = i; // assigning a unique id
        }

        // storing skills of people in decimal form
        vector<int> people_skill;
        for (auto& v : people) {

            int skill_bit = 0; // assigning first skill as 0th bit

            for (string& skill : v) {
                skill_bit =
                    skill_bit | (1 << skills[skill]); // adding skills to store
                                                      // in decimal format
            }

            people_skill.push_back(
                skill_bit); // skills of ith person in decimal form
        }

        int target_mask = pow(2, n) - 1; // required decimal no will be 2^n - 1
                                         // which means all skills are covered
        vector<int>
            result;       // result vector which stores the min people required
        vector<int> temp; // vector to store people taken in current branch

        solve(people_skill, 0, target_mask, temp, 0, result, dp);

        return result;
    }
};