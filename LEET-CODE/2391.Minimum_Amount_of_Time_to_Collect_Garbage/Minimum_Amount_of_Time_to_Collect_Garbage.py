# Define the function with input parameters garbage and travel lists and output an integer
class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        
        # Reverse the order of elements in the garbage and travel lists
        garbage.reverse()
        travel.reverse()
        
        # Join the elements in garbage list to a single string
        garbage2="".join(garbage)
        
        # Initialize variables to store the distances to each of the G, P and M locations
        a=0
        b=0
        c=0
        
        # Loop through the garbage list and find the distances to the first occurrence of G, P and M
        for i in range(len(garbage)):
            # If distances to all G, P and M are found, break out of the loop
            if(a!=0 and b!=0 and c!=0):
                break
            # Find the distance to G if it has not been found yet
            if ("G" in garbage[i]) and a==0:
                a=sum(travel[i:])
            # Find the distance to P if it has not been found yet
            if ("P" in garbage[i]) and b==0:
                b=sum(travel[i:])
            # Find the distance to M if it has not been found yet
            if ("M" in garbage[i]) and c==0:
                c=sum(travel[i:])
        
        # Calculate the total distance covered by the garbage truck
        sum1=len(garbage2)+a+b+c
        
        # Return the total distance
        return sum1


    



        