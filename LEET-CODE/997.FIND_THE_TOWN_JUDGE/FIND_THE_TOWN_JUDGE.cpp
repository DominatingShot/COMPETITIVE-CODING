class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) {
            if (trust.size() == 0) {
                return 1; // If there is only one person and no trust relationships, that person is the judge.
            }
            return -1; // Otherwise, there is no judge.
        }
        
        unordered_map<int, int> trustCounts; // Create a map to count the number of people who trust and are trusted.
        
        for (int i = 0; i < trust.size(); i++) {
            trustCounts[trust[i][1]]++; // Increment trust count for the person being trusted.
            trustCounts[trust[i][0]]--; // Decrement trust count for the person doing the trusting.
        }
        
        for (auto entry : trustCounts) {
            if (entry.second == n - 1) {
                return entry.first; // If someone is trusted by n-1 people, they are the judge.
            }
        }
        
        return -1; // If there is
