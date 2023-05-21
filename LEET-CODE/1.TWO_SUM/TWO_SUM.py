class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)  # Get the length of the input list
        for i in range(n):  # Iterate over the list elements
            for j in range(i + 1, n):  # Iterate over the remaining elements after i
                if nums[i] + nums[j] == target:  # Check if the pair sums up to the target
                    return [i, j]  # Return the indices of the two numbers
