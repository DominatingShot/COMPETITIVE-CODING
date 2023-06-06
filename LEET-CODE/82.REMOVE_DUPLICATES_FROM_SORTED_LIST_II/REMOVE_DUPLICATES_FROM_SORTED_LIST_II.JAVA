class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) 
            return head;
        ListNode temp = head;
        ListNode hNode = new ListNode(0);
        ListNode temp2 = hNode;
        while(temp != null && temp.next != null){
            if(temp.val == temp.next.val){
                while(temp.next != null && temp.val == temp.next.val){
                    temp = temp.next;
                }
                temp = temp.next;
            }
            else{
                temp2.next = temp;
                temp2 = temp2.next;
                temp = temp.next;
            }
          
        }
        temp2.next = temp;
        return hNode.next;
         
    }
}