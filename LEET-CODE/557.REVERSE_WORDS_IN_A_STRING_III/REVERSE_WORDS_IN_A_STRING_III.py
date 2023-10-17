class Solution:
    def reverseWords(self, s: str) -> str:
        # Split the input string 's' into a list of words using spaces as separators.
        l = s.split()
        
        # Iterate over the list of words.
        for i in range(len(l)):
            # Reverse each word by slicing it with [::-1] and update the list.
            l[i] = l[i][::-1]
        
        # Join the reversed words back into a single string with spaces in between.
        return " ".join(l)
