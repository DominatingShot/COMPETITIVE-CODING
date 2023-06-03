class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 10 and x >= 0:  # If x is a single-digit positive number
            return True
        else:
            x = str(x)  # Convert the integer x to a string for easy comparison

            for i in range(len(x)):  # Iterate through each character of the string
                if x[i] != x[len(x) - i - 1]:  # If the characters at symmetric positions don't match
                    return False

            return True  # If all characters match, x is a palindrome
