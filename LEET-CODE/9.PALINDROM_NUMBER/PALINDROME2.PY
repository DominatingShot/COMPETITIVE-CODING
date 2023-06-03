class Solution:
    def isPalindrome(self, x: int) -> bool:
        if str(x) == str(x)[::-1]:  # Check if the string representation of x is equal to its reverse
            return True
        else:
            return False
