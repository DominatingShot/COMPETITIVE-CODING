class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        count=0
        min_sum=k*threshold  # Calculate the minimum sum required for a subarray to meet the threshold
        
        sum1=sum(arr[0:k])  # Calculate the sum of the first subarray of length k
        
        if sum1 >= min_sum:
            count += 1  # If the sum meets the threshold, increment the count
        
        for i in range(1, len(arr)-k+1):
            sum1 = sum1 - arr[i-1] + arr[i+k-1]  # Update the sum by subtracting the first element and adding the next element
            
            if sum1 >= min_sum:
                count += 1  # If the updated sum meets the threshold, increment the count
        
        return count  # Return the final count
