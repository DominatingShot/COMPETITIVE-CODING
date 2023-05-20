class Solution(object):
    def isBipartite(self, graph):
        for i in range(len(graph)):
            color = [None] * len(graph)  # Create a list to store colors for each node
            color[i] = 1  # Assign the initial color to the current node
            q = []  # Create an empty queue
            q.append(i)  # Enqueue the current node
            while q:
                node = q.pop(0)  # Dequeue a node from the queue
                for j in graph[node]:  # Iterate through the neighbors of the current node
                    if color[j] is None:  # If the neighbor is not colored
                        color[j] = 1 - color[node]  # Assign a different color than the current node
                        q.append(j)  # Enqueue the neighbor
                    elif color[j] == color[node]:  # If the neighbor has the same color as the current node
                        return False  # The graph is not bipartite
        return True  # All nodes have been processed and the graph is bipartite

    