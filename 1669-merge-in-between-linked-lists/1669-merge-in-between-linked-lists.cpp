class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* curr = list1;
        ListNode* A = nullptr;
        ListNode* B = nullptr;

        int idx = 0;

        while (curr) {
            if (idx == a - 1) A = curr;
            if (idx == b + 1) B = curr;
            curr = curr->next;
            idx++;
        }

        A->next = list2;

        curr = list2;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = B;

        return list1;
    }
};
