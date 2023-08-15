class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;  // Initialize a variable to store the result
        
        for(char cs : s)
            c ^= cs;  // XOR operation with characters in string s
        
        for(char ct : t)
            c ^= ct;  // XOR operation with characters in string t
        
        return c;  // Return the resulting character which represents the added character
    };
}
