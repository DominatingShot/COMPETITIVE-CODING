class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, int> m; // Create a map to store character frequencies
        
        // Iterate through each character in string t and update their frequencies in the map
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        
        // Iterate through each character in string s and check if it is present in the map
        // If a character is not present or its frequency becomes 0, return false
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 0) {
                return false;
            }
            m[s[i]]--; // Decrement the frequency of the character in the map
        }
        
        return true; // All characters in s are found in t in the same order
    }
};
