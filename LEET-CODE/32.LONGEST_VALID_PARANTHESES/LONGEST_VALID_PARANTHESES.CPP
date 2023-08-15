using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // A stack to store the indices of opening parentheses.
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of an opening parenthesis onto the stack.
            } else {
                if (!st.empty()) {
                    st.pop(); // Pop the index of a matching opening parenthesis from the stack.
                } else {
                    st.push(i); // Push the index of the current closing parenthesis onto the stack.
                }
            }
        }
        
        int longest = st.size(); // Initialize the longest length with the remaining elements in the stack.
        
        if (st.empty())
            return longest; // If the stack is empty, all parentheses are valid, so return the length.
        
        int a = longest; // Store the current longest length.
        longest = 0; // Reset the longest length for further calculation.
        
        while (!st.empty()) {
            int b = st.top(); // Get the index of the top element in the stack.
            longest = max(longest, a - b - 1); // Update the longest length using the difference between indices.
            a = b; // Update 'a' for the next iteration.
            st.pop(); // Pop the top element from the stack.
        }
        
        longest = max(longest, a); // Update the longest length one last time.
        return longest; // Return the final longest length.
    }
};
