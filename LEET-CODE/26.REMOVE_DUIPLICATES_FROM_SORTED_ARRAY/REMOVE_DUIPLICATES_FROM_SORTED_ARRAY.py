class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        set_nums = set(nums)
        nums.clear()
        nums.extend(set_nums)
        return len(nums)