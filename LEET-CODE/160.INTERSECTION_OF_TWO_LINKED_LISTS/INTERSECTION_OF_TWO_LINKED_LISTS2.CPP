class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0;
        ListNode *temp = headA;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        temp = headB;
        int m=0;
        while(temp != NULL) {
            m++;
            temp = temp->next;
        }
        if(n > m) {
            int diff = n - m;
            while(diff--) {
                headA = headA->next;
            }
        } else {
            int diff = m - n;
            while(diff--) {
                headB = headB->next;
            }
        }
        while(headA != NULL && headB != NULL) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};