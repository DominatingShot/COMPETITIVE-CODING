class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false; // If the lengths of the two strings are different, they can't be anagrams
        }

        int arr[26] = {0}; // Create an array 'arr' to store character frequencies (for lowercase letters)
        
        // Calculate the frequency of characters in both strings 's' and 't'
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++; // Increment the count for character 's[i]' in the array 'arr'
            arr[t[i] - 'a']--; // Decrement the count for character 't[i]' in the array 'arr'
        }

        // At this point, if the two strings are anagrams, the 'arr' array should have all values as 0.
        // If there are any non-zero values, it means the characters' frequencies are different, and the strings are not anagrams.
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                return false; // Return false if any character frequency is non-zero
            }
        }
        
        return true; // If all characters' frequencies are zero, the strings are anagrams
    }
};
