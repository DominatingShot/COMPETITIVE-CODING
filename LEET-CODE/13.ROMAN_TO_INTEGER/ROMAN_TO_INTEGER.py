class Solution:
    def romanToInt(self, s: str) -> int:
        # Mapping of Roman numerals to their integer values
        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500,'M':1000}
        result = 0  # Variable to store the final result
        for i in range(len(s)):  # Loop through each character in the input string
            if i > 0 and roman[s[i]] > roman[s[i-1]]:
                # If the current value is greater than the previous value, it means subtraction is needed
                # We subtract twice the value of the previous character and add the current character's value
                result += roman[s[i]] - 2 * roman[s[i-1]]
            else:
                # Otherwise, simply add the value of the current character to the result
                result += roman[s[i]]
        return result  # Return the final result
