class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False  # If the lengths of the strings are different, they cannot be isomorphic

        d = {}  # Dictionary to store mappings from characters in 's' to characters in 't'

        for i in range(len(s)):
            if s[i] not in d:  # If the character from 's' is not yet mapped
                if t[i] in d.values():
                    return False  # If the character from 't' is already mapped to another character in 's', they are not isomorphic
                d[s[i]] = t[i]  # Map the character from 's' to 't'
            else:  # If the character from 's' is already mapped
                if d[s[i]] != t[i]:
                    return False  # If the mapped character from 's' doesn't match the character from 't', they are not isomorphic

        return True  # If all characters are successfully mapped and the mappings match, the strings are isomorphic

                
        