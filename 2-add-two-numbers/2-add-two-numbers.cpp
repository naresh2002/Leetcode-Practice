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
        ListNode *ans = new ListNode(-1);
        ListNode *node = ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
          node -> next = new ListNode((l1 -> val + l2 -> val + carry) % 10);
          carry = (l1 -> val + l2 -> val + carry) / 10;
          l1 = l1 -> next;
          l2 = l2 -> next;
          node = node -> next; 
        }
        while (l1 != NULL) {
          node -> next = new ListNode((l1 -> val + carry) % 10);
          carry = (l1 -> val + carry) / 10;
          l1 = l1 -> next;
          node = node -> next; 
        }
        while (l2 != NULL) {
          node -> next = new ListNode((l2 -> val + carry) % 10);
          carry = (l2 -> val + carry) / 10;
          l2 = l2 -> next;
          node = node -> next; 
        }
        if (carry) {
          node -> next = new ListNode(carry);
        }
        return ans -> next;
    }
};