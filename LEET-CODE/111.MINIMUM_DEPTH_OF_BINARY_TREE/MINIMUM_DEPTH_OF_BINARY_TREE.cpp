class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) 
            return 0; // If the root is null, the tree has no depth, so return 0
        
        Queue<TreeNode> q = new LinkedList<>(); // Create a queue to perform breadth-first traversal
        int h=0; // Initialize a variable to keep track of the current depth
        q.add(root); // Add the root node to the queue

        while(!q.isEmpty()){
            h++; // Increment the depth
            int size = q.size(); // Get the current number of nodes in the queue (which represents the number of nodes at the current level)

            for(int i=0; i<size; i++){
                TreeNode temp = q.poll(); // Remove the node at the front of the queue

                if(temp.left == null && temp.right == null)
                    return h; // If the current node has no left or right child, it is a leaf node, and its depth is the minimum depth of the tree

                if(temp.left != null)
                    q.add(temp.left); // Add the left child to the queue

                if(temp.right != null)
                    q.add(temp.right); // Add the right child to the queue
            }
        }
        
        return h; // Return the minimum depth of the binary tree
    }
}
