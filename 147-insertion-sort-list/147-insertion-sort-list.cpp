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
  
  // Copied from discussion
  ListNode* insertionSortList(ListNode* head) {
    if(head == nullptr) return head;

		ListNode *dummy = new ListNode(0);
		ListNode *prev = dummy, *curr = head, *nxt;

		while(curr){
			nxt = curr->next;
      while(prev->next && prev->next->val < curr -> val) {
        prev = prev -> next;
      }

			curr->next = prev->next;
			prev->next = curr;
            
			curr = nxt;
      prev = dummy;
		}
		return dummy->next;
  }
};