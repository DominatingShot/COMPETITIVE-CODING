import java.util.*;

public class Solution {
    public boolean hasCycle(ListNode head) {
        HashMap<ListNode, Integer> map = new HashMap<>();  // HashMap to store visited nodes

        while (head != null) {
            if (map.get(head) != null) {
                return true;  // If the current node is already present in the HashMap, it means there is a cycle
            }
            map.put(head, 1);  // Add the current node to the HashMap
            head = head.next;  // Move to the next node in the linked list
        }

        return false;  // If the loop completes without finding a cycle, return false
    }
}
