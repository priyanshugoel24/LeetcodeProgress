// Last updated: 02/05/2026, 22:48:16
class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> tokens;
        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {
            tokens.push_back(token);
        }

        stack<string> st;

        string simple_path = "";

        for(int i = 0; i < tokens.size(); i++){

            string curr_token = tokens[i];

            //in case of empty token or a single period we don't need to do anything as we are in the same directory
            if(curr_token == "." || curr_token == ""){
                continue;
            }
            
            //in case of double periods we are jumping to parent directory so pop the current directory
            if(curr_token == ".."){
                if(!st.empty()) st.pop();
                continue;
            }

            // we are jumping to a new directory
            st.push(curr_token);
        }

        if(st.empty()){
            return "/";
        }

        while(!st.empty()){
           
           simple_path = "/" + st.top() + simple_path;
           st.pop();
        }

        return simple_path;

    }
};