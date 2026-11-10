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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool followup = false;
    ListNode *head = nullptr, *prev = nullptr;
    ListNode *lp1 = l1, *lp2 = l2;
    while (lp1 != nullptr || lp2 != nullptr) {
      int l1Val = lp1 == nullptr ? 0 : lp1->val;
      int l2Val = lp2 == nullptr ? 0 : lp2->val;
      int val = l1Val + l2Val;
      if (followup)
        val++;
      followup = val >= 10;
      val = val % 10;
      ListNode *curr = new ListNode(val);
      if (head == nullptr)
      {
        head = curr;
        prev = head;
      } else {
        prev->next = curr;
        prev = prev->next;
      }
      if (lp1 != nullptr)
        lp1 = lp1->next;
      if (lp2 != nullptr)
        lp2 = lp2->next;
    }
    if (followup)
      prev->next = new ListNode(1);
    return head;
    }
};
