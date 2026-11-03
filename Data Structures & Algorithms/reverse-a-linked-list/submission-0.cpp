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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *c = head;
        ListNode *p = nullptr;
        while (c->next) {
            ListNode *t = c->next;
            c->next = p;
            p = c;
            c = t;
        }
        c->next = p;
        return c;
    }
};
