class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0; // Initialize a variable to count the length of list A.
        ListNode *temp = headA; // Create a temporary pointer to traverse list A.

        // Calculate the length of list A.
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        temp = headB; // Reset the temporary pointer to traverse list B.
        int m = 0; // Initialize a variable to count the length of list B.

        // Calculate the length of list B.
        while (temp != NULL) {
            m++;
            temp = temp->next;
        }

        if (n > m) {
            // If list A is longer than list B, move the head of list A forward by the difference in lengths.
            int diff = n - m;
            while (diff--) {
                headA = headA->next;
            }
        } else {
            // If list B is longer than list A, move the head of list B forward by the difference in lengths.
            int diff = m - n;
            while (diff--) {
                headB = headB->next;
            }
        }

        // Now, both lists are of equal length. Traverse both lists simultaneously until the intersection node is found.
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                // If the nodes are the same, it's the intersection point. Return it.
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        // If there's no intersection, return NULL.
        return NULL;
    }
};
