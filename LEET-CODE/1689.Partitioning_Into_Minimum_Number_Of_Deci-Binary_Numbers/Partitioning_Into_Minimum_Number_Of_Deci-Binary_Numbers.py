# Define a class named Solution.
class Solution:
    
    # Define a method named minPartitions that takes a string n as input and returns an integer.
    def minPartitions(self, n: str) -> int:
        # Convert the input string into a list of characters, then find the maximum character and convert it into an integer.
        return int(max(list(n)))
