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

    void dfs(ListNode* node, int &carry){

        if(node == NULL) return;

        dfs(node->next, carry);

        int val = (node->val * 2);

        int finalVal = val + carry;

        node->val = finalVal % 10;

        carry = finalVal / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        
        dfs(head, carry);

        if(carry != 0){
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};