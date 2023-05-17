class Solution:
    def average(self, salary: List[int]) -> float:
        salary.sort()  # Sort the list in ascending order
        
        # Calculate the average by excluding the minimum and maximum values
        return sum(salary[1:-1]) / (len(salary) - 2)
