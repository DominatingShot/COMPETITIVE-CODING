class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL; // If the input node is NULL, return NULL.
        }
        
        unordered_map<Node*, Node*> m; // Use a map to store mappings from original nodes to their clones.
        queue<Node*> q; // Use a queue for BFS traversal.
        
        // Create the clone of the first node and add it to the map.
        Node* firstNode = new Node(node->val);
        m[node] = firstNode;
        
        q.push(node); // Push the original node to the queue.
        
        // Perform BFS to clone the entire graph.
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* neighbor : curr->neighbors) {
                if (m.find(neighbor) == m.end()) {
                    // If the neighbor node is not in the map, create its clone and add it to the map.
                    Node* cloneNeighbor = new Node(neighbor->val);
                    m[neighbor] = cloneNeighbor;
                    q.push(neighbor); // Push the neighbor node to the queue for processing.
                }
                
                // Connect the clone of the current node to the clone of its neighbor.
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        
        return firstNode; // Return the clone of the first node, which is the starting point of the new graph.
    }
};
