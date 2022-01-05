/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *node = head;
    while (node != NULL) {
      if (node -> val == 1e6) {
        return true;
      }
      node -> val = 1e6;
      node = node -> next;
    }
    return false;
  }
};