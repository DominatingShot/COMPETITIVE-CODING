class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        def helper (nums,l,r):
            if (l>r):
                return l
            mid = (l+r)//2
            if (nums[mid]==target):
                return mid
            elif (nums[mid]>target):
                return helper(nums,l,mid-1)
            else:
                return helper(nums,mid+1,r)
        x = helper(nums,0,len(nums)-1)
        return x
        