class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> lastvisited;
        vector<int> result;
        int lastvisitedindex = 0;

        // Loop through the input vector of strings.
        for (int i = 0; i < words.size(); i++) {
            bool isnum = true;

            // Check if the current string consists of numeric characters.
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] >= '0' && words[i][j] <= '9') {
                    continue;
                } else {
                    isnum = false;
                    break;
                }
            }

            if (isnum) {
                // If the current string is numeric, convert it to an integer and store it.
                lastvisited.push_back(stoi(words[i]));
                lastvisitedindex = lastvisited.size();
            } else {
                // If the current string is not numeric, check if there are previously visited numeric values.
                if (lastvisitedindex == 0) {
                    result.push_back(-1);
                } else {
                    // Store the last visited numeric value and update the index.
                    result.push_back(lastvisited[lastvisitedindex - 1]);
                    lastvisitedindex--;
                }
            }
        }

        return result;
    }
};
