class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // Initialize a vector to store all valid partitions.
        vector<string> temp; // Initialize a temporary vector to store the current partition.

        // Call the helper function to generate partitions.
        helper(result, temp, s, 0);

        return result; // Return the vector of valid partitions.
    }

    void helper(vector<vector<string>>& result, vector<string>& temp, string s, int index) {
        if (index == s.size()) {
            // If we have reached the end of the string, add the current partition to the result.
            result.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (ispalindrome(s.substr(index, i - index + 1))) {
                // If the current substring is a palindrome, add it to the current partition.
                temp.push_back(s.substr(index, i - index + 1));

                // Recursively continue partitioning the remaining substring.
                helper(result, temp, s, i + 1);

                // Backtrack by removing the last added substring to explore other possibilities.
                temp.pop_back();
            }
        }
    }

    bool ispalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
