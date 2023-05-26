class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // Check if either list is null
        if (list1 == null || list2 == null) {
            // Return the non-null list as the merged list
            if (list1 == null) 
                return list2;
            else 
                return list1;
        }
        
        // Create a new ListNode to store the merged list
        ListNode head = new ListNode();
        ListNode temp = head;
        
        // Determine the initial head value by comparing the first elements of both lists
        if (list1.val < list2.val) {
            head.val = list1.val;
            list1 = list1.next;
        } else {
            head.val = list2.val;
            list2 = list2.next;
        }
        
        // Merge the two lists by iterating until either list is exhausted
        while (list1 != null && list2 != null) {
            // Compare the current elements of both lists and add the smaller value to the merged list
            if (list1.val < list2.val) {
                temp.next = new ListNode(list1.val);
                list1 = list1.next;
            } else {
                temp.next = new ListNode(list2.val);
                list2 = list2.next;
            }
            temp = temp.next; // Move the temp pointer to the next node
        }
        
        // If there are remaining elements in list1, add them to the merged list
        while (list1 != null) {
            temp.next = new ListNode(list1.val);
            list1 = list1.next;
            temp = temp.next;
        }
        
        // If there are remaining elements in list2, add them to the merged list
        while (list2 != null) {
            temp.next = new ListNode(list2.val);
            list2 = list2.next;
            temp = temp.next;
        }
        
        return head; // Return the merged list
    }
}
