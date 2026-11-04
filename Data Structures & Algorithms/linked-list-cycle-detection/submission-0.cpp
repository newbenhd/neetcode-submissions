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
        ListNode *p = head;
        ListNode *faster = p;
        while (p && faster)
        {
            if (faster->next)
            {
                faster = faster->next;
                if (faster->next)
                    faster = faster->next;
                else
                    break;
            } else
                break;
            if (p->next)
                p = p->next;
            else
                break;
            if (p == faster)
                return true;
        }
        return false;
    }
};
