class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        unordered_map<ListNode*, int> m; // Create an unordered map to store nodes and their occurrence count.

        // Traverse both linked lists and store each visited node in the map.
        while (headA != NULL && headB != NULL) {
            m[headA]++; // Increase the occurrence count for the node in list A.
            if (m[headA] == 2) {
                return headA; // If the node appears twice, it's the intersection point.
            }

            m[headB]++; // Increase the occurrence count for the node in list B.
            if (m[headB] == 2) {
                return headB; // If the node appears twice, it's the intersection point.
            }

            headA = headA->next; // Move to the next node in list A.
            headB = headB->next; // Move to the next node in list B.
        }

        // If one of the lists has more nodes, continue traversing it and checking for intersections.
        while (headA != NULL) {
            m[headA]++;
            if (m[headA] == 2) {
                return headA;
            }
            headA = headA->next;
        }

        while (headB != NULL) {
            m[headB]++;
            if (m[headB] == 2) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL; // If no intersection is found, return NULL.
    }
};
