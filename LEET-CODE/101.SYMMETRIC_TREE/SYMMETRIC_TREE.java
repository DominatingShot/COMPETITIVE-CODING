import java.util.Queue;
//BFS
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) // If the root is null, return true
            return true;
        Queue<TreeNode> queue = new LinkedList<>(); // Queue to store the nodes of the tree
        queue.add(root.left); // Adding the left child of the root to the queue
        queue.add(root.right); // Adding the right child of the root to the queue
        while(!queue.isEmpty()){
            TreeNode left = queue.poll(); // Removing the first node from the queue
            TreeNode right = queue.poll(); // Removing the second node from the queue
            if(left == null && right == null) // If both the nodes are null, continue
                continue;
            if(left == null || right == null) // If one of the nodes is null, return false
                return false;
            if(left.val != right.val) // If the values of the nodes are not equal, return false
                return false;
            queue.add(left.left); // Adding the left child of the left node to the queue
            queue.add(right.right); // Adding the right child of the right node to the queue
            queue.add(left.right); // Adding the right child of the left node to the queue
            queue.add(right.left); // Adding the left child of the right node to the queue
        }
        return true; // Returning true        
    }
}