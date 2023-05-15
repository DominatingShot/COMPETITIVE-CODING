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
    public ListNode swapNodes(ListNode head, int k) {
    ListNode a1,b1;
    a1=head;
    b1=head;
    int count = 1;
    while(count<k){
        a1 = a1.next;
        count++;
    }
    ListNode temp=a1;
    while (temp.next != null) {
        b1 = b1.next;
        temp= temp.next;
    }
    System.out.println(a1.val+" "+b1.val);
    int temp1 = a1.val;
    a1.val = b1.val;
    b1.val = temp1;
    return head;
    }
}