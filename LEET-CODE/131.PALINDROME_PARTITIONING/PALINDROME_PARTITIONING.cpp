class Solution {
public:
    vector<vector<string>> partition(string x) {
        vector<vector<string>> ans; // Initialize a 2D vector 'ans' to store the palindrome partitions

        int s = x.size(); // Get the size of the input string 'x'

        for (int i = 0; i < s; i++) {
            vector<string> temp; // Initialize a temporary vector 'temp' to store the palindrome substrings for a given start index 'i'

            for (int j = i; j < s; j++) {
                if (isPalindrome(x.substr(i, j - i + 1))) { // Check if the substring from 'i' to 'j' (inclusive) is a palindrome
                    temp.push_back(x.substr(i, j - i + 1)); // If it is a palindrome, add it to the temporary vector 'temp'
                }
            }

            ans.push_back(temp); // Add the temporary vector 'temp' to the final answer vector 'ans'
        }

        return ans; // Return the 2D vector containing all possible palindrome partitions
    }

    bool isPalindrome(string x) {
        int s = x.size(); // Get the size of the input string 'x'

        for (int i = 0; i < s / 2; i++) {
            if (x[i] != x[s - i - 1]) { // Check if the characters at 'i' and 's-i-1' (opposite ends) do not match
                return false; // If they don't match, the string is not a palindrome, return false
            }
        }

        return true; // If the loop completes without finding any mismatch, the string is a palindrome, return true
    }
};
