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
  
  // Cannot be done by fast and slow pointers as fast pointer might skip cycle initiation point and directly be equal to slow
  
  ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode*, int> m;
    while (head != NULL) {
      if (m.find(head) != m.end()) {
        return head;
      }
      m[head]++;
      head = head -> next;
    }
    return NULL;
  }
};