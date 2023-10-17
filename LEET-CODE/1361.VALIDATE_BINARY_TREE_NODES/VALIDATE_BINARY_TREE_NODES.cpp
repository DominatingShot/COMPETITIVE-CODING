class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int> q;
        vector<int> arr(n, 0);
        int count = 0;

        // Step 1: Count the number of incoming edges to each node.
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                arr[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                arr[rightChild[i]]++;
            }
        }

        int x = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                x = i; // Find the node with no incoming edges (potential root).
            }
            arr[i] = 0;
        }

        // Step 2: Perform a breadth-first traversal starting from the potential root.
        q.push(x);
        while (!q.empty()) {
            x = q.front();
            q.pop();

            if (arr[x] == 1) {
                return false; // If a node has more than one incoming edge, it's not a valid binary tree.
            }

            arr[x]++;
            count++;

            if (leftChild[x] != -1) {
                q.push(leftChild[x]);
            }
            if (rightChild[x] != -1) {
                q.push(rightChild[x]);
            }
        }

        // Step 3: Check if the traversal visited all nodes.
        if (count == n) {
            return true; // If the count of visited nodes equals 'n', it's a valid binary tree.
        }

        return false; // Otherwise, it's not a valid binary tree.
    }
};
