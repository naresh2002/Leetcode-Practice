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
  ListNode* reverse(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
  }
  
  void reorderList(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast -> next) {
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    ListNode* head2 = slow -> next;
    slow -> next = NULL;
    head2 = reverse(head2);
    
    ListNode *head1 = head;
    while (head2) {
      ListNode* temp = head2 -> next;
      head2 -> next = head1 -> next;
      head1 -> next = head2;
      
      head1 = head1 -> next -> next;
      head2 = temp;
    }
  }
};