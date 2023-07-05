class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)  # Initialize a dynamic programming array with 1s
        maxans = 1  # Variable to store the maximum length of the increasing subsequence
        
        if len(nums) == 0:
            return 0  # If the array is empty, the length of the longest increasing subsequence is 0
        
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    # If the current number nums[j] is greater than nums[i],
                    # it can be included in the increasing subsequence
                    
                    dp[j] = max(dp[j], dp[i] + 1)
                    # Update dp[j] with the maximum length of the increasing subsequence
                    # By either not including the current number or including it
                    
                    maxans = max(maxans, dp[j])
                    # Update the maximum length if dp[j] is greater than the current maxans
        
        return maxans

    
                    
                