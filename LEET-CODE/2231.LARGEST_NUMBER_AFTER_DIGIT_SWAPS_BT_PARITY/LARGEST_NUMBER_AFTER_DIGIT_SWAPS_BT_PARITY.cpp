class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);  // Convert the integer 'num' to a string for easier digit manipulation.

        for (int i = 0; i < s.size(); i++) {
            bool even = (s[i] - '0') % 2 == 0;  // Check if the current digit is even.

            for (int j = i + 1; j < s.size(); j++) {
                if (even == (s[j] - '0') % 2 == 0) {
                    // If both digits have the same even/odd status, compare them.
                    if (s[i] < s[j]) {
                        swap(s[i], s[j]);  // Swap the digits to maximize the resulting integer.
                    }
                }
            }
        }

        return stoi(s);  // Convert the modified string back to an integer and return it.
    }
};
