class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size(); // Number of words
        int l = words[0].size(); // Length of each word
        int len = s.length(); // Length of the input string
        vector<int> ans; // Vector to store the resulting indices
        
        // Check for invalid inputs
        if (len < n * l || n == 0 || l == 0)
            return ans;
        
        unordered_map<string, int> m; // Hash map to store word frequency
        for (int i = 0; i < n; i++)
            m[words[i]]++; // Count the frequency of each word
        
        int window = n * l; // Total length of the window
        int i = 0; // Start index of the window
        
        // Slide the window through the string
        while (i + window <= len) {
            if (check(m, s.substr(i, window), l)) {
                ans.push_back(i); // If window is a valid substring, store the index
            }
            i++; // Move the window
        }
        return ans; // Return the resulting indices
    }
    
    // Function to check if the substring is a valid concatenation of words
    bool check(unordered_map<string, int> m, string s, int l) {
        for (int i = 0; i < s.length(); i += l) {
            string temp = s.substr(i, l); // Extract a word from the substring
            if (m.find(temp) != m.end()) {
                m[temp]--; // Decrement the frequency of the word
                if (m[temp] == -1)
                    return false; // If frequency becomes negative, it's not a valid substring
            } else {
                return false; // If word is not in the word list, it's not a valid substring
            }
        }
        return true; // All words are valid in the substring
    }
};
