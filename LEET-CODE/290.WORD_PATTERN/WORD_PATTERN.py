class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        x = s.split()  # Split the string 's' into a list of words

        if len(pattern) != len(x):
            return False  # If the lengths of the pattern and word list are different, they cannot match the pattern

        d1 = {}  # Dictionary to store mappings from characters in 'pattern' to words in 'x'

        for i in range(len(pattern)):
            if pattern[i] not in d1:  # If the character from 'pattern' is not yet mapped
                if x[i] in d1.values():
                    return False  # If the word from 'x' is already mapped to another character in 'pattern', they do not match the pattern
                d1[pattern[i]] = x[i]  # Map the character from 'pattern' to the word from 'x'
            else:  # If the character from 'pattern' is already mapped
                if d1[pattern[i]] != x[i]:
                    return False  # If the mapped word from 'x' does not match the current word, they do not match the pattern

        return True  # If all characters are successfully mapped and the mappings match, the pattern and words match

