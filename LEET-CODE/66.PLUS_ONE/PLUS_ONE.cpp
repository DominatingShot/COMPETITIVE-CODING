class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1; // Start from the rightmost digit.

        digits[i]++; // Add 1 to the rightmost digit.

        if (digits[i] < 10)
            return digits; // If the digit is less than 10, there's no need for further processing.

        int carry = 1; // Initialize a carry variable to 1, indicating we need to carry over.

        while (i > 0 && carry) {
            digits[i] = 0; // Set the current digit to 0.
            digits[--i]++; // Increment the digit to the left.

            if (digits[i] < 10)
                carry = 0; // If the digit is less than 10, no need to carry over anymore.
        }

        if (carry) {
            digits[0] = 0; // If there's still a carry, set the leftmost digit to 0.
            digits.insert(digits.begin(), 1); // Insert a new digit 1 at the beginning.
        }

        return digits; // Return the modified vector, which now represents the result of adding one.
    }
};
