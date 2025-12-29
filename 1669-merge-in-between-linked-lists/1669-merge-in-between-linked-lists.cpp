/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* curr = list1;

        ListNode* A = NULL;
        ListNode* B = NULL;

        int count = 0;

        while(curr){
            if(count == a - 1){
                A = curr;
            }
            else if(count == b + 1){
                B = curr;
            }

            curr = curr->next;
            count++;
        }

        A->next = list2;

        if(B){
            ListNode* temp = list2;
            while(temp->next){
                temp = temp->next;
            }

            if(B) temp->next = B;
        }

        return list1;
    }
};