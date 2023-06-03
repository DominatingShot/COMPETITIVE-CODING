class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs = sorted(strs, key=len)  # Sort the list of strings in ascending order based on their lengths

        prefix = ''  # Initialize an empty string to store the longest common prefix

        if len(strs) == 0:  # If the list is empty, there are no common prefixes
            return ""
        else:
            x = strs[0]  # Assign the shortest string in the sorted list to the variable x

            for i in range(len(x)):  # Iterate through each character of the shortest string
                for j in range(1, len(strs)):  # Iterate through each string starting from the second one
                    if x[i] != strs[j][i]:  # If the current character doesn't match in any of the strings
                        return prefix  # Return the longest common prefix found so far

                prefix += x[i]  # Append the current character to the prefix string

        return prefix  # Return the longest common prefix found



    
    