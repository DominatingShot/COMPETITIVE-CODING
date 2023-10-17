class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;  // Initialize a long variable to track the total size of the decoded string.
        int n = s.size();

        // Calculate the total size of the decoded string by iterating through the characters.
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int repeat = s[i] - '0';
                size *= repeat;
            } else {
                size++;
            }
        }

        // Start decoding the string in reverse order to optimize memory usage.
        for (int i = n - 1; i >= 0; i--) {
            k %= size;  // Reduce k if it exceeds the size of the current substring.

            // If k is 0 and the current character is a letter, return it as the result.
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }

            // If the current character is a digit, reduce the size accordingly.
            if (isdigit(s[i])) {
                int repeat = s[i] - '0';
                size /= repeat;
            } else {
                size--;
            }
        }

        // This line should not be reached.
        return "";
    }
};
