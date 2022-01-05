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
    while (head != NULL) {
      if (head -> val == 1e6) {
        return true;
      }
      head -> val = 1e6;
      head = head -> next;
    }
    return false;
  }
};