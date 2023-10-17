class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> index(26, 0);  // Create an array to store the last index of each character.
        for (int i = 0; i < s.size(); i++) {
            index[s[i] - 'a'] = i;  // Store the last index of each character in the 'index' array.
        }
        vector<bool> visited(26, false);  // Create a boolean array to track visited characters.
        stack<char> st;  // Create a stack to build the result string.

        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i] - 'a']) continue;  // If the character is already visited, skip it.

            while (!st.empty() && st.top() > s[i] && index[st.top() - 'a'] > i) {
                // Check if the current character should be placed before the characters in the stack.
                visited[st.top() - 'a'] = false;  // Mark the character as not visited.
                st.pop();  // Remove the character from the stack.
            }

            st.push(s[i]);  // Push the current character onto the stack.
            visited[s[i] - 'a'] = true;  // Mark the character as visited.
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;  // Build the result string in reverse order.
            st.pop();  // Remove characters from the stack.
        }
        return ans;  // Return the result string with duplicate letters removed.
    }
};
