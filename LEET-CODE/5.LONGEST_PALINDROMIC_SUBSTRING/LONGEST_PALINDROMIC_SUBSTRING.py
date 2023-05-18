class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)  # Get the length of the input string
        
        if(s == s[::-1]):  # Check if the string is already a palindrome
            return s  # If it is, return the string as the longest palindrome
        
        length -= 1  # Decrease the length by 1
        # Iterate while the length is greater than 1
        while length > 1:
            # Iterate over substrings of length 'length' within the input string
            for i in range((len(s)-length)+1):
                # Check if the substring is a palindrome
                if(s[i:length+i] == s[i:length+i][::-1]):
                    return s[i:length+i]  # If it is, return the palindrome substring
            
            length -= 1  # Decrease the length by 1 for the next iteration
        
        return s[0]  # If no palindromic substring is found, return the first character of the input string

    
            