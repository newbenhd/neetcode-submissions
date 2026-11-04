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
    void reorderList(ListNode* head) {
        // find mid node
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *first = head, *second = slow;
        // reverse the second list
        ListNode *p = nullptr;
        while (second)
        {
            ListNode *temp = second->next;
            second->next = p;
            p = second;
            second = temp;
        }
        // reassign second pointer to head of the reversed list
        second = p;
        // merge two list
        while (first && second)
        {
            if (first->next == second)
                break;
            ListNode *temp = first->next;
            first->next = second;
            ListNode *temp2 = second->next;
            second->next = temp;
            first = temp;
            second = temp2;
        }
    }
};
