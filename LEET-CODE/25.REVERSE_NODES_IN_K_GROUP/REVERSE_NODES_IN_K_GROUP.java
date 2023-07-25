class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || !checkvalid(head, k)) {
            return head;
        }
        ListNode curr = head;
        ListNode prev = null;
        ListNode next = null;
        int count = 0;
        while (count < k && curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count += 1;
        }
        head.next = reverseKGroup(next, k);
        return prev;
    }
    public Boolean checkvalid(ListNode head, int k) {
        int count = 0;
        ListNode temp = head;
        while(count < k && temp != null) {
            temp = temp.next;   
            count += 1;
        }
        if (count < k) {
            return false;
        }
        return true;
    }
}



