class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        int n = len/k;
        int r = len%k;
        temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            result.push_back(temp);
            int i = 0;
            while(i<n){
                prev = temp;
                temp = temp->next;
                i++;
            }
            if(r>0){
                prev = temp;
                temp = temp->next;
                r--;
            }
            if(prev!=NULL){
                prev->next = NULL;
            }
        }
        while(result.size()<k){
            result.push_back(NULL);
        }
        return result;
    }
};