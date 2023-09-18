class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> graph; // Create an adjacency list to represent the graph.
        
        // Populate the adjacency list using the given edges.
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, 0); // Create a boolean array to track visited nodes.
        queue<int> q; // Use a queue for BFS traversal.
        q.push(start); // Start BFS traversal from the "start" node.
        visited[start] = 1; // Mark the "start" node as visited.
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == end)
                return true; // If the "end" node is reached, there's a valid path.
            
            // Explore neighbors of the current node.
            for (auto& node : graph[curr]) {
                if (!visited[node]) {
                    visited[node] = 1; // Mark the neighbor as visited.
                    q.push(node); // Push the neighbor to the queue for further exploration.
                }
            }
        }
        
        return false; // If the "end" node is not reached, there's no valid path.
    }
};
