// Last updated: 02/05/2026, 22:40:48
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        int size = folder.size();

        vector<string> final_folders;

        sort(begin(folder), end(folder)); // parent folders will be to the left and subfolders will be to the right

        final_folders.push_back(folder[0]); // first folder in sorted vector won't have any parent

        for(int idx = 1; idx < size; idx++){

            string currFolder = folder[idx];

            // check if last folder in final folders is a parent of the curr folder
            string possible_parent = final_folders.back();
            possible_parent += '/';

            bool is_not_parent = currFolder.find(possible_parent);

            // if it is not a parent of curr folder, we can push it to final folders
            if(is_not_parent){
                final_folders.push_back(currFolder);
            }
        }

        return final_folders;
    }
};