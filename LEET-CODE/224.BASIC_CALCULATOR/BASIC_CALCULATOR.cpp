class Solution {
public:
    int calculate(string s) {
        stack<int> st; // Stack to hold numbers and signs
        int res = 0; // The final result of the calculation
        int sign = 1; // The sign of the current segment
        int num = 0; // The current number being formed
        
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); // Forming the number
            }
            else if(s[i] == '+') {
                res += sign * num; // Add the current number to the result with appropriate sign
                sign = 1; // Reset the sign for the next segment
                num = 0; // Reset the number for the next segment
            }
            else if(s[i] == '-') {
                res += sign * num; // Add the current number to the result with appropriate sign
                sign = -1; // Reset the sign for the next segment
                num = 0; // Reset the number for the next segment
            }
            else if(s[i] == '(') {
                st.push(res); // Push the current result to the stack
                st.push(sign); // Push the current sign to the stack
                res = 0; // Reset the result for the inner segment
                sign = 1; // Reset the sign for the inner segment
            }
            else if(s[i] == ')') {
                res += sign * num; // Add the current number to the result with appropriate sign
                res *= st.top(); // Multiply the result with the sign from the stack
                st.pop(); // Pop the sign from the stack
                res += st.top(); // Add the previous result from the stack
                st.pop(); // Pop the previous result from the stack
                num = 0; // Reset the number for the next segment
            }      
        }
        
        if(num != 0) {
            res += sign * num; // Add the last number to the result with appropriate sign
        }
        
        return res; // Return the final result
    } 
};
