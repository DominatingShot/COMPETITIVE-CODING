class Solution:
    def jump(self, nums: List[int]) -> int:
        j = 0  # Variable to store the minimum number of jumps required
        l = r = 0  # Pointers to define the current jump range

        while r < len(nums) - 1:
            far = 0  # Variable to store the furthest reachable index in the current jump range

            # Iterate over the elements in the current jump range to find the furthest reachable index
            for i in range(l, r + 1):
                far = max(far, i + nums[i])

            l = r + 1  # Move the left pointer to the next jump range
            r = far  # Update the right pointer to the furthest reachable index
            j += 1  # Increment the jump count

        return j  # Return the minimum number of jumps required

    
        

            
        