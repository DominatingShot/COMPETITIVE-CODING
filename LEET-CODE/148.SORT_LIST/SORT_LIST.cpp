class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Base case: If the list is empty or has only one element, it's already sorted.
        }
        
        ListNode* dummy = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Use slow and fast pointers to find the middle of the linked list.
        while (fast != NULL && fast->next != NULL) {
            dummy = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        dummy->next = NULL; // Split the list into two halves.
        
        ListNode* l1 = sortList(head); // Recursively sort the first half.
        ListNode* l2 = sortList(slow); // Recursively sort the second half.
        
        return merge(l1, l2); // Merge the sorted halves.
    }
    
    // Merge two sorted linked lists.
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0); // Create a dummy node to simplify the code.
        ListNode* temp = dummy;
        
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        
        // If there are remaining elements in either list, append them.
        if (head1 != NULL) {
            temp->next = head1;
        }
        if (head2 != NULL) {
            temp->next = head2;
        }
        
        return dummy->next; // Return the merged sorted list.
    }
};
