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
      hm[nullptr] = nullptr;
      Node *current = head;
      while (current != nullptr)
      {
        Node *c = new Node(current->val);
        hm[current] = c;
        current = current->next;
      }
      current = head;
      while (current != nullptr)
      {
        hm[current]->next = hm[current->next];
        hm[current]->random = hm[current->random];
        current = current->next;
      }
      return hm[head];
    }
};
