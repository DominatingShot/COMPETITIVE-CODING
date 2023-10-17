class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1"; // Base case: The first term of the "count and say" sequence is "1."
        }
        if (n == 2) {
            return "11"; // Base case: The second term of the sequence is "11," as it describes the previous term ("1").
        }
        string x = "11"; // Initialize x with the second term of the sequence, "11."

        for (int j = 3; j <= n; j++) {
            string y = ""; // Initialize an empty string y to build the next term.
            int count = 1; // Initialize a count for the current character.
            char c = x[0]; // Initialize c with the first character of the previous term.

            for (int i = 1; i < x.size(); i++) {
                if (x[i] == c) {
                    count++; // If the current character is the same as the previous character, increment the count.
                } else {
                    // If the current character is different from the previous character, append the count and character to y.
                    y += to_string(count);
                    y += c;
                    c = x[i]; // Update c to the new character.
                    count = 1; // Reset the count.
                }
            }
            // Append the count and character for the last sequence of identical characters.
            y += to_string(count);
            y += c;
            x = y; // Update x with the next term for the next iteration.
        }
        return x; // Return the final term of the "count and say" sequence.
    }
};
