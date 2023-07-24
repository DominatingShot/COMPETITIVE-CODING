#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1; // Start from the least significant digit of 'a'
        int j = b.size() - 1; // Start from the least significant digit of 'b'
        int carry = 0;        // Initialize carry to 0 for binary addition
        string res = "";      // Initialize an empty string to store the result

        // Perform binary addition while there are digits left in 'a' or 'b', or there is a carry
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry = carry + a[i--] - '0'; // Convert character to integer and add to 'carry'
            }
            if (j >= 0) {
                carry = carry + b[j--] - '0'; // Convert character to integer and add to 'carry'
            }

            // Append the least significant bit of 'carry' to the result string
            res = char(carry % 2 + '0') + res;

            carry = carry / 2; // Update 'carry' for the next iteration (carry can be 0 or 1)
        }

        return res; // Return the binary sum as a string
    }
};
