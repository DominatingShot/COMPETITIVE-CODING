from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Create an empty dictionary to store the frequencies of each number
        dic = {}

        # Iterate over the input list
        for i in nums:
            # If the number is already present in the dictionary, increment its frequency
            if i in dic:
                dic[i] += 1
            # If the number is encountered for the first time, initialize its frequency to 1
            else:
                dic[i] = 1

        # Create an empty list to store the top k frequent numbers
        l = []

        # Sort the dictionary keys based on their values in ascending order
        x = sorted(dic, key=dic.get)

        # Retrieve the top k frequent numbers in descending order from the sorted keys
        l = x[-1:-k-1:-1]

        # Return the list of top k frequent numbers
        return l
