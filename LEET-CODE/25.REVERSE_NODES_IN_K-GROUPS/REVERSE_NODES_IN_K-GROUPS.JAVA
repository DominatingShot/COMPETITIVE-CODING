class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || head.next == null){
            return head;
        }
        else{
            int left = 1;
            int right = k;
            ListNode temp = head;
            int count = 1;
            boolean flag = true
            while(flag){
                while(count < k){
                    if(temp.next == null){
                        flag = false;
                        break;
                    }
                }
                    temp = temp.next;
                    count++;
                reverseBetween(head, left, right);
                left = right + 1;
                right = left + k - 1;
            }
        }
        return head;
    }

    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummyHead = new ListNode(); // Create a dummy node
    
        dummyHead.next = head; // Assign the head of the original list to dummyHead's next
        ListNode prev = dummyHead; // Set prev initially as dummyHead
    
        for (int i = 1; i < left; i++) {
            prev = prev.next; // Traverse to the node before the left position
        }
    
        ListNode curr = prev.next; // Set curr as the node at the left position
    
        for (int i = 0; i < right - left; i++) {
            ListNode fwd = curr.next; // Store the next node
            curr.next = fwd.next; // Reverse the link by skipping fwd
            fwd.next = prev.next; // Set the next of fwd as the current first node in the sublist
            prev.next = fwd; // Set the next of prev as fwd, thus inserting it into the sublist
        }
    
        return dummyHead.next; // Return the head of the modified list
    }
}
