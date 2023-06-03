/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0)  // If the input array is empty, return null
            return null;
        else if (lists.length == 1)  // If there is only one list in the array, return that list
            return lists[0];
        else {
            int mid = lists.length / 2;  // Find the middle index to split the array into two halves
            ListNode[] left = new ListNode[mid];  // Create a new array to store the left half of lists
            ListNode[] right = new ListNode[lists.length - mid];  // Create a new array to store the right half of lists

            for (int i = 0; i < mid; i++)  // Populate the left array with the lists from the original array
                left[i] = lists[i];
            for (int i = mid; i < lists.length; i++)  // Populate the right array with the lists from the original array
                right[i - mid] = lists[i];

            ListNode mergedLeft = mergeKLists(left);  // Recursively merge the left half
            ListNode mergedRight = mergeKLists(right);  // Recursively merge the right half

            return merge(mergedLeft, mergedRight);  // Merge the left and right halves and return the merged result
        }
    }

    public ListNode merge(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();  // Create a dummy node as the head of the merged list
        ListNode temp = head;  // Create a temporary node to traverse the merged list

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {  // If the value in l1 is smaller, append it to the merged list
                temp.next = new ListNode(l1.val);
                l1 = l1.next;  // Move to the next node in l1
            } else {  // If the value in l2 is smaller or equal, append it to the merged list
                temp.next = new ListNode(l2.val);
                l2 = l2.next;  // Move to the next node in l2
            }
            temp = temp.next;  // Move the temp pointer forward
        }

        while (l1 != null) {  // Append the remaining nodes from l1 to the merged list
            temp.next = new ListNode(l1.val);
            l1 = l1.next;
            temp = temp.next;
        }
        while (l2 != null) {  // Append the remaining nodes from l2 to the merged list
            temp.next = new ListNode(l2.val);
            l2 = l2.next;
            temp = temp.next;
        }

        return head.next;  // Return the merged list by skipping the dummy head node
    }
}