class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        dp = [0] * (len(nums) + 1)  # Create a dynamic programming array
        
        dp[0] = 0  # Base case: no houses, no money
        dp[1] = nums[0]  # Base case: only one house, rob it
        
        for i in range(2, len(nums) + 1):
            # For each house, calculate the maximum amount of money that can be robbed
            # Either by skipping the current house (dp[i-1]) or by robbing it (dp[i-2] + nums[i-1])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])
        
        return dp[len(nums)]  # Return the maximum amount of money that can be robbed
