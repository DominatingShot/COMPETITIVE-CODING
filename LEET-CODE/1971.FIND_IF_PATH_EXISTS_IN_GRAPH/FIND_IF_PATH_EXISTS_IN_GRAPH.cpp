class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true; // If the source and destination are the same, there's always a valid path.
        }
        
        vector<vector<int>> graph(n); // Create an adjacency list to represent the graph.
        
        // Populate the adjacency list using the given edges.
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n, false); // Create a boolean array to track visited nodes.
        queue<int> q; // Use a queue for BFS traversal.
        q.push(source); // Start BFS traversal from the "source" node.
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == destination) {
                return true; // If the "destination" node is reached, there's a valid path.
            }
            
            visited[curr] = true; // Mark the current node as visited.
            
            // Explore neighbors of the current node.
            for (auto neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    q.push(neighbor); // Push the unvisited neighbor to the queue.
                }
            }
        }
        
        return false; // If the "destination" node is not reached, there's no valid path.
    }
};
