import java.util.*;

public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null)
            return false;  // If the head is null, there is no cycle

        ListNode slow = head;  // Slow pointer starts at the head
        ListNode fast = head.next;  // Fast pointer starts at the next node

        while (slow != fast) {
            if (fast == null || fast.next == null)
                return false;  // If the fast pointer reaches the end of the list, there is no cycle

            slow = slow.next;  // Move the slow pointer one step forward
            fast = fast.next.next;  // Move the fast pointer two steps forward
        }

        return true;  // If the slow and fast pointers meet, there is a cycle
    }
}
