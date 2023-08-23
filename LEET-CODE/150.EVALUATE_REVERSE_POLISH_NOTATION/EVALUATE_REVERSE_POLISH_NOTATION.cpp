class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;  // Initialize a stack to hold numbers during evaluation
        
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/") {
                int a = s.top();  // Get the first operand from the top of the stack
                s.pop();  // Pop the operand from the stack
                int b = s.top();  // Get the second operand from the new top of the stack
                s.pop();  // Pop the second operand from the stack
                
                // Perform the operation based on the operator
                if(tokens[i] == "*") {
                    s.push(a * b);  // Push the result of multiplication onto the stack
                } else if(tokens[i] == "+") {
                    s.push(a + b);  // Push the result of addition onto the stack
                } else if(tokens[i] == "-") {
                    s.push(b - a);  // Push the result of subtraction onto the stack
                } else {
                    s.push(b / a);  // Push the result of division onto the stack
                }
            } else {
                s.push(stoi(tokens[i]));  // Push the number onto the stack
            }
        }
        
        return s.top();  // The final result after all calculations
    }
};
