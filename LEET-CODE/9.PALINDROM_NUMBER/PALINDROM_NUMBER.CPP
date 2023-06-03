#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {  // If x is negative, it can't be a palindrome
            return false;
        } else {
            string s = to_string(x);  // Convert x to a string for easy comparison
            int i = 0;  // Starting index of the string
            int j = s.length() - 1;  // Ending index of the string

            while (i < j) {  // Iterate until the middle of the string
                if (s[i] != s[j]) {  // If the characters at symmetric positions don't match
                    return false;  // x is not a palindrome
                }
                i++;  // Move the left pointer towards the center
                j--;  // Move the right pointer towards the center
            }
            return true;  // If all characters match, x is a palindrome
        }
    }
};
