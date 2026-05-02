// Last updated: 02/05/2026, 22:42:33
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        int no_of_boats = 0;

        sort(begin(people), end(people));

        int left = 0, right = n - 1;

        while(left <= right){

            if(people[left] + people[right] <= limit){

                left++;
                right--;

            }else{
                
                right--;
            }

            no_of_boats += 1;

        }

        return no_of_boats;

    }
};