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
  int n;
  ListNode *var;
public:
  Solution(ListNode* head) {
    var = head;
    ListNode* node = head;
    n = 0;
    while (node != NULL) {
      node = node -> next;
      n++;
    }
  }

  int getRandom() {
    int p = rand() % n;
    ListNode *tmp = var;
    while (p > 0) {
      tmp = tmp -> next;
      p--;
    }
    return tmp->val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */