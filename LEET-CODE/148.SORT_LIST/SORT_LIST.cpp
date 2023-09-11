class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            dummy = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        dummy->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
    ListNode* merge(ListNode* Head1,ListNode* Head2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(Head1 != NULL && Head2 != NULL) {
            if(Head1->val < Head2->val) {
                temp->next = Head1;
                Head1 = Head1->next;
            } else {
                temp->next = Head2;
                Head2 = Head2->next;
            }
            temp = temp->next;
        }
        if(Head1 != NULL) {
            temp->next = Head1;
        }
        if(Head2 != NULL) {
            temp->next = Head2;
        }
        return dummy->next;
    }
};