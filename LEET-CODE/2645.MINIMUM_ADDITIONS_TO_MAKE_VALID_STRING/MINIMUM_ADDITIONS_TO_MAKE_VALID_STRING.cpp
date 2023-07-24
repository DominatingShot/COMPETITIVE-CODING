class Solution {
public:
    int addMinimum(string word) {
        int ans = 0; // Initialize 'ans' to store the minimum number of characters needed
        for (int i = 0; i < word.size();) {
            int count = 0; // Initialize 'count' to count the occurrences of 'a', 'b', and 'c'

            // If the current character is 'a', increment 'count' and move to the next character
            if (word[i] == 'a') {
                count++;
                i++;
            }

            // If the current character is 'b', increment 'count' and move to the next character
            if (i < word.size() && word[i] == 'b') {
                count++;
                i++;
            }

            // If the current character is 'c', increment 'count' and move to the next character
            if (i < word.size() && word[i] == 'c') {
                count++;
                i++;
            }

            // Add (3 - count) to 'ans', as it represents the number of characters needed to make "abc" a subsequence
            ans += 3 - count;
        }
        return ans; // Return the minimum number of characters needed to make "abc" a subsequence
    }
};
