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
  ListNode *list;
  bool solve(ListNode *head) {
    if (head == NULL) {
      return true;
    }
    bool ans = solve (head -> next) & (list -> val == head -> val);
    list = list -> next;
    return ans;
  }
  
  bool isPalindrome(ListNode* head) {
    list = head;
    return solve(head);
  }
};