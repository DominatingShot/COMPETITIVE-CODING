class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        unordered_map<ListNode*, int> m;
        while(headA != NULL && headB != NULL) {
            m[headA]++;
            if(m[headA] == 2) {
                return headA;
            }
            m[headB]++;
            if(m[headB] == 2) {
                return headB;
            }
            headA = headA->next;
            headB = headB->next;
        }
        while(headA != NULL) {
            m[headA]++;
            if(m[headA] == 2) {
                return headA;
            }
            headA = headA->next;
        }
        while(headB != NULL) {
            m[headB]++;
            if(m[headB] == 2) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};