class Solution:
    def isValid(self, s: str) -> bool:
        l = []  # Create an empty list to act as a stack

        for i in s:  # Iterate through each character in the input string
            if i == '(' or i == '{' or i == '[':
                l.append(i)  # If the character is an opening bracket, push it onto the stack
            else:
                if len(l) == 0:
                    return False  # If the stack is empty and we encounter a closing bracket, it's not balanced
                if i == ')' and l[-1] == '(':  # If the character is a closing bracket and matches the top of the stack
                    l.pop()  # Pop the opening bracket from the stack
                elif i == '}' and l[-1] == '{':
                    l.pop()
                elif i == ']' and l[-1] == '[':
                    l.pop()
                else:
                    return False  # If the character doesn't match the top of the stack, it's not balanced

        if len(l) == 0:
            return True  # If the stack is empty at the end, all brackets were balanced
        else:
            return False  # If the stack is not empty, some opening brackets were not closed
