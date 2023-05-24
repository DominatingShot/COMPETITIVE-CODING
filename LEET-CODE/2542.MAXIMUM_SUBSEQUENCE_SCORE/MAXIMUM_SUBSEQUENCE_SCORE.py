import heapq
from typing import List

class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        result = 0                          # Variable to store the maximum score
        total_sum = 0                       # Variable to store the current sum of nums1 values
        heap = []                           # Min-heap to store the k largest nums1 values
        merged = [(nums2[i], nums1[i]) for i in range(len(nums1))]  # Merge corresponding elements from nums1 and nums2
        merged.sort(reverse=True)           # Sort the merged list in descending order based on nums2 values
        
        for maxOf2, num1Val in merged:      # Iterate through the merged list
            if len(heap) == k:              # If the heap has k elements, remove the smallest element
                total_sum -= heapq.heappop(heap)
            
            total_sum += num1Val            # Add the current nums1 value to the total sum
            heapq.heappush(heap, num1Val)   # Push the current nums1 value to the heap
            
            if len(heap) == k:              # If the heap has k elements, calculate the score
                result = max(result, total_sum * maxOf2)
        
        return result                       # Return the maximum score
