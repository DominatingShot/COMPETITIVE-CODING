class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [sys.maxsize] * (amount + 1)  # Initialize a dynamic programming array with maximum values
        dp[0] = 0  # Base case: 0 coins needed for amount 0
        
        for i in range(1, amount + 1):
            for j in coins:
                if i >= j:
                    dp[i] = min(dp[i], dp[i - j] + 1)
                    # Update dp[i] with the minimum number of coins required to make amount i
                    # By either using the current coin j (1 additional coin) or not using it
                    # Choose the minimum of the two options
            
        if dp[amount] == sys.maxsize:
            return -1  # If no combination of coins can make the desired amount, return -1
        
        return dp[amount]  # Return the minimum number of coins required to make the amount

                