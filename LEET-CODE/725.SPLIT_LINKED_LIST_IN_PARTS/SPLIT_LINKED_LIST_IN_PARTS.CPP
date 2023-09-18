class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result; // Vector to store the split parts.
        int len = 0; // Variable to store the length of the original linked list.
        ListNode* temp = head; // Temporary pointer to traverse the linked list.
        
        // Calculate the length of the linked list.
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        
        int n = len / k; // Number of nodes in each part.
        int r = len % k; // Number of remaining nodes to be distributed.
        temp = head; // Reset the temporary pointer to the beginning of the linked list.
        ListNode* prev = NULL; // Pointer to the previous node.

        // Iterate through the linked list to split it into parts.
        while (temp != NULL) {
            result.push_back(temp); // Add the current node to the result vector.
            int i = 0;

            // Move 'temp' and 'prev' pointers 'n' steps to split the part.
            while (i < n) {
                prev = temp;
                temp = temp->next;
                i++;
            }

            // If there are remaining nodes, distribute them among the parts.
            if (r > 0) {
                prev = temp;
                temp = temp->next;
                r--;
            }

            // Disconnect the end of the current part from the next part.
            if (prev != NULL) {
                prev->next = NULL;
            }
        }

        // Add any remaining NULL parts to the result.
        while (result.size() < k) {
            result.push_back(NULL);
        }

        return result; // Return the vector of split parts.
    }
};
