/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node *, Node *> hm;
      Node *current = head, *copiedCurrent = nullptr, *copiedHead = nullptr;
      while (current != nullptr)
      {
        Node *c = new Node(current->val);
        if (copiedHead == nullptr)        
          copiedHead = c;
        if (copiedCurrent == nullptr)
          copiedCurrent = c;
        else
        {
          copiedCurrent->next = c;
          copiedCurrent = c;
        }
        hm[current] = c;
        current = current->next;
      }
      current = head;
      copiedCurrent = copiedHead;
      while (current != nullptr)
      {
        if (current->random != nullptr)
          copiedCurrent->random = hm[current->random];
        current = current->next;
        copiedCurrent = copiedCurrent->next;
      }
      return copiedHead;
    }
};
