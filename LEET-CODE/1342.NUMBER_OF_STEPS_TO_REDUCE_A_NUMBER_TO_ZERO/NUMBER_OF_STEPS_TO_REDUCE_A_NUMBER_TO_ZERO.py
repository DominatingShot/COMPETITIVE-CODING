class Solution(object):
    def numberOfSteps(self, num):
        count = 0  # Initialize a counter to keep track of the number of steps taken
        
        # Continue the loop until the number becomes zero
        while num != 0:
            if num % 2 == 0:  # If the number is even
                num = num / 2  # Divide the number by 2
                count += 1  # Increment the count by 1
            else:
                num -= 1  # If the number is odd, subtract 1
                count += 1  # Increment the count by 1
        
        return count  # Return the final count
