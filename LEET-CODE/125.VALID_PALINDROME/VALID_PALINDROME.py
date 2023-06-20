class Solution:
    def isPalindrome(self, s: str) -> bool:
        j = len(s) - 1  # Initialize j as the index of the last character in the string
        i = 0  # Initialize i as the index of the first character in the string

        while i < j:  # Loop until the pointers cross each other
            if not s[i].isalnum():  # Check if the character at index i is alphanumeric
                i += 1  # Move i to the next character
                continue  # Continue to the next iteration of the loop

            if not s[j].isalnum():  # Check if the character at index j is alphanumeric
                j -= 1  # Move j to the previous character
                continue  # Continue to the next iteration of the loop

            if s[i].lower() != s[j].lower():  # Check if the characters at indices i and j are not equal (case-insensitive)
                return False  # Return False if the characters are not equal

            i += 1  # Move i to the next character
            j -= 1  # Move j to the previous character

        return True  # Return True if the string is a palindrome


            