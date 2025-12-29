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

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        int carry = 0;
        ListNode* curr = head;

        while(curr){
            int sum = curr->val * 2 + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if(!curr->next && carry)
                curr->next = new ListNode(0);

            curr = curr->next;
        }

        return reverse(head);
    }

};