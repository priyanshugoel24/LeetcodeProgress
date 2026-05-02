// Last updated: 02/05/2026, 22:43:36
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int> st;

        vector<int> finalAsteroids;

        for(int i = 0; i < n; i++){

            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else{

                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }

                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                }

                else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }

        while(!st.empty()){
            finalAsteroids.push_back(st.top()); st.pop();
        }

        reverse(finalAsteroids.begin(), finalAsteroids.end());

        return finalAsteroids;
    }
};