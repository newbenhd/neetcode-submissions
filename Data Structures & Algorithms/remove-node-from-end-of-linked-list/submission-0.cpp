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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Find the length
        int count = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            count++;
        }
        // calculate the jump count
        int jump = count - n - 1;
        // edge case; if negative remove the head
        if (jump < 0) return head->next;
        // jump node list
        ListNode* jumpNode = head;
        while (jump != 0) {
            jumpNode = jumpNode->next;
            jump--;
        }
        // remove jump node
        if (jumpNode->next)
            jumpNode->next = jumpNode->next->next;
        else
            jumpNode->next = nullptr;
        return head;
    }
};
