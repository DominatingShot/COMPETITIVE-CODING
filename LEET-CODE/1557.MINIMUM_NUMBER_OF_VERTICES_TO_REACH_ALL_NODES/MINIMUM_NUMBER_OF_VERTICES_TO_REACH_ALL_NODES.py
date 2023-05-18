from ast import List
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        # Create a boolean array to track nodes
        nodes = [False]*n
        
        # Mark nodes that have incoming edges
        for i in edges:
            nodes[i[1]] = True
        
        # Initialize an empty list to store the result
        ans = []
        
        # Iterate through all nodes
        for i in range(n):
            # Check if the node has no incoming edges
            if nodes[i] == False:
                # Add the node to the result list
                ans.append(i)
        
        # Return the list of nodes with no incoming edges
        return ans





        