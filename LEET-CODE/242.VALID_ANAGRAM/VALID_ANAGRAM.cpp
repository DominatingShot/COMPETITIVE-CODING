class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m; // Create a map to store character frequencies
        if (s.length() != t.length()) {
            // If the lengths of the two strings are different, they can't be anagrams
            return false;
        }
        
        // Calculate the frequency of characters in both strings 's' and 't'
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++; // Increment the count for character 's[i]' in the map
            m[t[i]]--; // Decrement the count for character 't[i]' in the map
        }

        // At this point, if the two strings are anagrams, the map 'm' should have all values as 0.
        // If there are any non-zero values, it means the characters' frequencies are different, and the strings are not anagrams.
        for (auto i : m) {
            if (i.second != 0) {
                return false; // Return false if any character frequency is non-zero
            }
        }
        
        return true; // If all characters' frequencies are zero, the strings are anagrams
    }
};
