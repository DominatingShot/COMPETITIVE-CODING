class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m; // A map that maps a frequency vector to a vector of strings.
        
        // Iterate through each string in the input vector.
        for (string s : strs) {
            vector<int> v(26, 0); // A frequency vector to store the frequency of characters in the current string.
            for (char c : s) {
                v[c - 'a']++; // Increment the count of the character in the frequency vector.
            }
            m[v].push_back(s); // Add the current string to the corresponding frequency vector's group in the map.
        }
        
        vector<vector<string>> ans; // The final answer vector of grouped anagrams.
        
        // Iterate through each group of anagrams in the map.
        for (auto p : m) {
            ans.push_back(p.second); // Push the group of anagrams to the answer vector.
        }
        
        return ans; // Return the vector of grouped anagrams.
    }
};
