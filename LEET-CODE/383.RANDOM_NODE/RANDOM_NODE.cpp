class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;  // Map to store the frequency of characters in the magazine string

        for (int i = 0; i < magazine.size(); i++) {
            m[magazine[i]]++;  // Increment the frequency of each character in the magazine string
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (--m[ransomNote[i]] < 0) {
                return false;  // If the frequency of any character in the ransom note is higher than that in the magazine, it cannot be constructed
            }
        }

        return true;  // If all characters in the ransom note can be constructed using characters from the magazine, return true
    }
};
