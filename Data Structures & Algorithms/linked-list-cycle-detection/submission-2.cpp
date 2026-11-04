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
    bool hasCycle(ListNode* head) {
        int uniqValue = 2000;
        ListNode unique(uniqValue); // 2000 is unique number that will never appear in the head list
        while (head != nullptr)
        {
            if (head->val == uniqValue)
                return true;
            ListNode *temp = head->next;
            head->next = &unique;
            head = temp;
        }
        return false;
    }
};
