import sys

class Solution(object):
    def numSquares(self, n):
        square = [1]  # List to store perfect squares less than or equal to 'n'
        x = 3

        # Generate perfect squares up to 'n'
        while square[-1] + x <= n:
            square.append(square[-1] + x)
            x += 2

        dp = []  # List to store the minimum number of perfect squares needed for each number up to 'n'
        
        for i in range(n + 1):
            if i == 0 or i == 1:
                dp.append(i)  # Base case: 0 and 1 require 0 and 1 perfect squares, respectively
            else:
                z = i
                c = sys.maxsize  # Initialize 'c' to a large value

                #for loop is used to find the optimal solution for the given number 
                #Example 
                #12 = [9,1,1,1]
                #This will be the greedy solution
                #we use for loop to check for other possible solutions
                #12 = [4,4,4]
                #12 = [1,1,1,1,1,1,1,1,1,1,1,1]
                #and we obtain the optimal solution
                for j in range(len(square) - 1, -1, -1):
                    if z - square[j] >= 0:
                        z = z - square[j]
                        tc = 1 + dp[z]  # Compute the count of perfect squares needed for 'z'
                        c = min(c, tc)  # Update 'c' with the minimum count found so far
                        z = i  # Reset 'z' for the next iteration

                dp.append(c)  # Store the minimum count in 'dp'

        return dp[-1]  # Return the minimum number of perfect squares needed for 'n'